#include "game_state.h"

#include <cassert>

#include "goods.h"
#include "universal.h"

int GameState::GetNumberOfSeagulls() const {
    return number_of_seagulls_;
}

int GameState::GetNumberOfPlayers() const {
    return number_of_players_;
}

Navigation* GameState::GetNavigationCard() {
    assert(not_used_navigation_cards_.size() > 0);
    Navigation* current_card_ = not_used_navigation_cards_[0];
    not_used_navigation_cards_.pop_front();
    return current_card_;
 }

Item* GameState::GetItemCard() {
    assert(not_used_items_.size() > 0);
    Item* current_card_ = not_used_items_[0];
    not_used_items_.pop_front();
    return current_card_;
}

int GameState::GetIdCard(Card* card) {
    return get_id_using_card_[card];
}

Card* GameState::GetCard(int id) {
    return get_card_using_id_[id];
}

Player* GameState::GetPlayerUsingPlayerId(int id) {
    return get_player_[id];
}

 int GameState::GetSizeOfOutboard() const {
    return outboard_.size();
 }

Character* GameState::GetCharacterOutboard(std::size_t i) const {
    assert(0 <= i < not_used_navigation_cards_.size());
    return outboard_[i];
}

void GameState::GetChosen(int id) {
    std::size_t index = 0;
    while (current_choice_[index] != id) {
        index++;
    }
    for (std::size_t i = index; i < current_choice_.size() - 1; i++) {
        current_choice_[i] = current_choice_[i + 1];
    }
    current_choice_.pop_back();
}

Character* GameState::GetFought(std::size_t index) const {
    return fought_[index];
}

Character* GameState::GetRowed(std::size_t index) const {
    return rowed_[index];
}

std::size_t GameState::GetSizeOfFought() const {
    return fought_.size();
}

std::size_t GameState::GetSizeOfRowed() const {
    return rowed_.size();
}

std::vector<std::string> GetAvailableActions(int player, int id);
    bool IsActionAvailable(int player, int id);

void GameState::SetNumberOfSeagulls(int number_of_seagulls) {
    for (auto x : sListeners) {
        x->notify(number_of_seagulls);
    }
    number_of_seagulls_ = number_of_seagulls;
}

void GameState::AddCardFought(Character* current_character) {
    fought_.push_back(current_character);
}

void GameState::AddCardRowed(Character* current_character) {
    rowed_.push_back(current_character);
}

void GameState::AddCardOutboard(Character* current_character) {
    for (auto x : oListeners) {
        x->notify(get_id_using_card_[current_character]);
    }
    outboard_.push_back(current_character);
}

void GameState::AddNotUsedNavigation(Navigation* current_navigation) {
    not_used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddTheRestNavigation() {
    for (auto x : remNotUsedListeners) {
        x->notify(current_choice_);
    }
    for (std::size_t i = 0; i < current_choice_.size(); i++) {
        Navigation* current_navigation = dynamic_cast<Navigation*> (get_card_using_id_[current_choice_[i]]);
        not_used_navigation_cards_.push_back(current_navigation);
        RemoveAvailableAction(current_choice_[i], "ChooseNavigationCard");
    }
}

void GameState::AddNotUsedItem(Item* current_item) {
    not_used_items_.push_back(current_item);
}

void GameState::AddUsedNavigation(Navigation* current_navigation) {
    for (auto x : remUsedListeners) {
        x->notify(get_id_using_card_[current_navigation]);
    }
    used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddChosenNavigation(int id) {
    chosen_navigation_card_ = id;
}

void GameState::AddUsedItem(Item* current_item) {
    for (auto x : remUsedListeners) {
        x->notify(get_id_using_card_[current_item]);
    }
    used_items_.push_back(current_item);
}

void GameState::AddToChoice(int to_choice) {
    for (auto x : addListeners) {
        x->notify(to_choice);
    }
    current_choice_.push_back(to_choice);
}

void GameState::AddPlayerCharacter(int player, int id) {
    Character* current_character = dynamic_cast<Character*> (get_card_using_id_[id]); 
    get_character_id_using_player_.push_back(current_character);
    get_player_using_character_id_[current_character] = player;
}

void GameState::AddCharacter(Character* character) {
    characters_.push_back(character);
}

void GameState::BoundCardWithId(int id, Card* card) {
    get_id_using_card_[card] = id;
    get_card_using_id_.push_back(card);
}

void GameState::SetPlayer(Player* player) {
    get_player_.push_back(player);
}

void GameState::SetLast(int player) {
    last_player_ = player;
}

void GameState::AddAvailableAction(int id, std::string action, int player = 10) {
    if (player == 10) {
        for (std::size_t i = 0; i < number_of_players_; i++) {
            available_actions_[i][id].push_back(action);
            is_action_[i][id][action] = 1;
        }
        return;
    }
    available_actions_[player][id].push_back(action);
    is_action_[player][id][action] = 1;
}

void GameState::RemoveAvailableAction(int id, std::string action, int player = 10) {
    if (player == 10) {
        for (std::size_t i = 0; i < number_of_players_; i++) {
            std::size_t j = 0;
            for (; j < available_actions_[i][id].size(); j++) {
                if (available_actions_[i][id][j] == action) {
                    break;
                }
            }
            for (; j < available_actions_[i][id].size() - 1; j++) {
                available_actions_[i][id][j] = available_actions_[i][id][j + 1]; 
            }
            is_action_[i][id][action] = 0;
        }
        return;
    }
    std::size_t j = 0;
    for (; j < available_actions_[player][id].size(); j++) {
        if (available_actions_[player][id][j] == action) {
            break;
        }
    }
    for (; j < available_actions_[player][id].size() - 1; j++) {
        available_actions_[player][id][j] = available_actions_[player][id][j + 1]; 
    }
    is_action_[player][id][action] = 0;
}


void GameState::FinishRound() {
    fought_.clear();
    rowed_.clear();
    outboard_.clear();
    current_choice_.clear();
}

GameState::GameState(std::size_t number_of_players)
    : number_of_players_(number_of_players)
{
    available_actions_.resize(number_of_players_, std::vector<std::vector<std::string>>(60));
    is_action_.resize(number_of_players_, std::vector<std::unordered_map<std::string, bool>>(60));
}
//     LadyLauren lady_lauren;
//     game_state.AddCharacter(&lady_lauren);
//     game_state.BoundCardWithId(0, &lady_lauren);
//     game_state.AddToChoice(0);
//     SirStephen sir_stephen;
//     game_state.AddCharacter(&sir_stephen);
//     game_state.BoundCardWithId(1, &sir_stephen);
//     game_state.AddToChoice(1);
//     Captain captain;
//     game_state.AddCharacter(&captain);
//     game_state.BoundCardWithId(2, &captain);
//     game_state.AddToChoice(2);
//     FirstMate first_mate;
//     game_state.AddCharacter(&first_mate);
//     game_state.BoundCardWithId(3, &first_mate);
//     game_state.AddToChoice(3);
//     Frenchy frenchy;
//     game_state.AddCharacter(&frenchy);
//     game_state.BoundCardWithId(4, &frenchy);
//     game_state.AddToChoice(4);
//     TheKid the_kid;
//     game_state.AddCharacter(&the_kid);
//     game_state.BoundCardWithId(5, &the_kid);
//     game_state.AddToChoice(5);

//     Player A;
//     game_state.SetPlayer(&A);
//     A.SetCharacter(&lady_lauren);
//     action.ChooseCharacterCard(0, 0);
//     Player B;
//     game_state.SetPlayer(&B);
//     B.SetCharacter(&sir_stephen);
//     action.ChooseCharacterCard(1, 1);
//     Player C;
//     game_state.SetPlayer(&C);
//     C.SetCharacter(&captain);
//     action.ChooseCharacterCard(2, 2);
//     Player D;
//     game_state.SetPlayer(&D);
//     D.SetCharacter(&first_mate);
//     action.ChooseCharacterCard(3, 3);
//     Player E;
//     game_state.SetPlayer(&E);
//     E.SetCharacter(&frenchy);
//     action.ChooseCharacterCard(4, 4);
//     Player F;
//     game_state.SetPlayer(&F);
//     F.SetCharacter(&the_kid);
//     action.ChooseCharacterCard(5, 5);

//     Water water_1;
//     water_1.SetName("Вода");
//     water_1.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_1.SetPosition(false);
//     game_state.AddNotUsedItem(&water_1);
//     game_state.BoundCardWithId(6, &water_1);

//     Water water_2;
//     water_2.SetName("Вода");
//     water_2.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_2.SetPosition(false);
//     game_state.AddNotUsedItem(&water_2);
//     game_state.BoundCardWithId(7, &water_2);

//     Water water_3;
//     water_3.SetName("Вода");
//     water_3.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_3.SetPosition(false);
//     game_state.AddNotUsedItem(&water_3);
//     game_state.BoundCardWithId(8, &water_3);

//     Water water_4;
//     water_4.SetName("Вода");
//     water_4.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_4.SetPosition(false);
//     game_state.AddNotUsedItem(&water_4);
//     game_state.BoundCardWithId(9, &water_4);

//     Water water_5;
//     water_5.SetName("Вода");
//     water_5.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_5.SetPosition(false);
//     game_state.AddNotUsedItem(&water_5);
//     game_state.BoundCardWithId(10, &water_5);

//     Water water_6;
//     water_6.SetName("Вода");
//     water_6.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water_6.SetPosition(false);
//     game_state.AddNotUsedItem(&water_6);
//     game_state.BoundCardWithId(11, &water_6);

//     Navigation nav_1;
//     nav_1.SetThirstyRowers(true);
//     nav_1.SetOutboard({&first_mate});
//     nav_1.SetThirsty({&captain, &first_mate});
//     game_state.AddNotUsedNavigation(&nav_1);
//     game_state.BoundCardWithId(12, &nav_1);


//     Navigation nav_2;
//     nav_2.SetThirstyRowers(true);
//     nav_2.SetThirstyFighters(true);
//     nav_2.SetOutboard({&captain});
//     nav_2.SetThirsty({&sir_stephen});
//     game_state.AddNotUsedNavigation(&nav_2);
//     game_state.BoundCardWithId(13, &nav_2);
    
//     Navigation nav_3;
//     nav_3.SetThirstyFighters(true);
//     nav_3.SetOutboard({&frenchy});
//     nav_3.SetThirsty({&captain, &first_mate, &lady_lauren});
//     game_state.AddNotUsedNavigation(&nav_3);
//     game_state.BoundCardWithId(14, &nav_3);

//     Navigation nav_4;
//     nav_4.SetOutboard({&captain});
//     nav_4.SetThirsty({&captain});
//     game_state.AddNotUsedNavigation(&nav_4);
//     game_state.BoundCardWithId(15, &nav_4);

//     Navigation nav_5;
//     nav_5.SetSeagull(1);
//     nav_5.SetOutboard({&frenchy});
//     nav_5.SetThirsty({&captain, &first_mate, &sir_stephen});
//     game_state.AddNotUsedNavigation(&nav_5);
//     game_state.BoundCardWithId(16, &nav_5);

//     Navigation nav_6;
//     nav_6.SetSeagull(1);
//     nav_6.SetThirstyRowers(true);
//     nav_6.SetOutboard({&sir_stephen});
//     nav_6.SetThirsty({&captain, &the_kid});
//     game_state.AddNotUsedNavigation(&nav_6);
//     game_state.BoundCardWithId(17, &nav_6);

//     Navigation nav_7;
//     nav_7.SetThirstyFighters(true);
//     nav_7.SetOutboard({&sir_stephen});
//     nav_7.SetThirsty({&captain, &lady_lauren});
//     game_state.AddNotUsedNavigation(&nav_7);
//     game_state.BoundCardWithId(18, &nav_7);

//     Navigation nav_8;
//     nav_8.SetOutboard({&the_kid});
//     nav_8.SetThirsty({&captain, &first_mate, &frenchy, &lady_lauren});
//     game_state.AddNotUsedNavigation(&nav_8);
//     game_state.BoundCardWithId(19, &nav_8);

//     Navigation nav_9;
//     nav_9.SetOutboard({&sir_stephen});
//     nav_9.SetThirsty({&sir_stephen, &captain});
//     game_state.AddNotUsedNavigation(&nav_9);
//     game_state.BoundCardWithId(20, &nav_9);

//     Navigation nav_10;
//     nav_10.SetSeagull(1);
//     nav_10.SetThirstyFighters(true);
//     nav_10.SetOutboard({&captain});
//     nav_10.SetThirsty({&first_mate});
//     game_state.AddNotUsedNavigation(&nav_10);
//     game_state.BoundCardWithId(21, &nav_10);

//     Navigation nav_11;
//     nav_11.SetSeagull(1);
//     nav_11.SetThirstyFighters(true);
//     nav_11.SetOutboard({&captain});
//     nav_11.SetThirsty({&first_mate});
//     game_state.AddNotUsedNavigation(&nav_11);
//     game_state.BoundCardWithId(22, &nav_11);

//     Navigation nav_12;
//     nav_12.SetSeagull(1);
//     nav_12.SetThirstyFighters(true);
//     nav_12.SetOutboard({&captain});
//     nav_12.SetThirsty({&first_mate});
//     game_state.AddNotUsedNavigation(&nav_12);
//     game_state.BoundCardWithId(23, &nav_12);