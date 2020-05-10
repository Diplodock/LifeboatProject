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

std::vector<std::string> GameState::GetAvailableActions(int player, int id) {
    return available_actions_[player][id];
}

bool GameState::IsActionAvailable(int player, int id, std::string action) {
    return is_action_[player][id][action];
}

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
    get_card_using_id_[id] = card;
}

void GameState::SetPlayer(Player* player) {
    get_player_.push_back(player);
}

void GameState::SetLast(int player) {
    last_player_ = player;
}

void GameState::AddAvailableAction(int id, std::string action, int player) {
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

void GameState::RemoveAvailableAction(int id, std::string action, int player) {
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

int GameState::GetSizeOfChoice() const {
    return current_choice_.size();
}


GameState::GameState(std::size_t number_of_players)
    : number_of_players_(number_of_players)
{
    available_actions_.resize(number_of_players_, std::vector<std::vector<std::string>>(200));
    is_action_.resize(number_of_players_, std::vector<std::unordered_map<std::string, bool>>(200));

    AddCharacter(&firstMate);
    BoundCardWithId(0, &firstMate);
    AddAvailableAction(0, "TryToSwap");
    AddAvailableAction(0, "TryToTakeGoods");
    AddAvailableAction(0, "TryToGiveGoods");
    AddAvailableAction(0, "Fight");

    AddCharacter(&captain);
    BoundCardWithId(1, &captain);
    AddAvailableAction(1, "TryToSwap");
    AddAvailableAction(1, "TryToTakeGoods");
    AddAvailableAction(1, "TryToGiveGoods");
    AddAvailableAction(1, "Fight");

    AddCharacter(&frenchy);
    BoundCardWithId(2, &frenchy);
    AddAvailableAction(2, "TryToSwap");
    AddAvailableAction(2, "TryToTakeGoods");
    AddAvailableAction(2, "TryToGiveGoods");
    AddAvailableAction(2, "Fight");

    AddCharacter(&drHarter);
    BoundCardWithId(3, &drHarter);
    AddAvailableAction(3, "TryToSwap");
    AddAvailableAction(3, "TryToTakeGoods");
    AddAvailableAction(3, "TryToGiveGoods");
    AddAvailableAction(3, "Fight");

    AddCharacter(&kid);
    BoundCardWithId(4, &kid);
    AddAvailableAction(4, "TryToSwap");
    AddAvailableAction(4, "TryToTakeGoods");
    AddAvailableAction(4, "TryToGiveGoods");
    AddAvailableAction(4, "Fight");

    AddCharacter(&ladyLauren);
    BoundCardWithId(5, &ladyLauren);
    AddAvailableAction(5, "TryToSwap");
    AddAvailableAction(5, "TryToTakeGoods");
    AddAvailableAction(5, "TryToGiveGoods");
    AddAvailableAction(5, "Fight");

    AddCharacter(&sirStephen);
    BoundCardWithId(6, &sirStephen);
    AddAvailableAction(6, "TryToSwap");
    AddAvailableAction(6, "TryToTakeGoods");
    AddAvailableAction(6, "TryToGiveGoods");
    AddAvailableAction(6, "Fight");

    AddCharacter(&wong);
    BoundCardWithId(7, &wong);
    AddAvailableAction(7, "TryToSwap");
    AddAvailableAction(7, "TryToTakeGoods");
    AddAvailableAction(7, "TryToGiveGoods");
    AddAvailableAction(7, "Fight");

    SetPlayer(&player1);
    SetPlayer(&player2);
    SetPlayer(&player3);
    SetPlayer(&player4);
    SetPlayer(&player5);
    SetPlayer(&player6);
    SetPlayer(&player7);
    SetPlayer(&player8);

    std::vector<Character*> randCharacters= characters_;
    for (std::size_t i = 0; i < characters_.size(); i++) {
        int j = rand() % (characters_.size());
        Character* swaped = randCharacters[i];
        randCharacters[i] = randCharacters[j];
        randCharacters[j] = swaped;
    }
    player1.SetCharacter(randCharacters[0]);
    player2.SetCharacter(randCharacters[1]);
    player3.SetCharacter(randCharacters[2]);
    player4.SetCharacter(randCharacters[3]);
    player5.SetCharacter(randCharacters[4]);
    player6.SetCharacter(randCharacters[5]);
    player7.SetCharacter(randCharacters[6]);
    player8.SetCharacter(randCharacters[7]);

    AddPlayerCharacter(0, get_id_using_card_[player1.GetCharacter()]);
    AddPlayerCharacter(1, get_id_using_card_[player2.GetCharacter()]);
    AddPlayerCharacter(2, get_id_using_card_[player3.GetCharacter()]);
    AddPlayerCharacter(3, get_id_using_card_[player4.GetCharacter()]);
    AddPlayerCharacter(4, get_id_using_card_[player5.GetCharacter()]);
    AddPlayerCharacter(5, get_id_using_card_[player6.GetCharacter()]);
    AddPlayerCharacter(6, get_id_using_card_[player7.GetCharacter()]);
    AddPlayerCharacter(7, get_id_using_card_[player8.GetCharacter()]);

    painting1.SetKind("painting");
    painting1.SetPoints(3);
    BoundCardWithId(24, &painting1);
    AddNotUsedItem(&painting1);
    AddAvailableAction(24, "TakeItemsAction");

    painting2.SetKind("painting");
    painting2.SetPoints(2);
    BoundCardWithId(25, &painting2);
    AddNotUsedItem(&painting2);
    AddAvailableAction(25, "TakeItemsAction");

    painting3.SetKind("painting");
    painting3.SetPoints(3);
    BoundCardWithId(26, &painting3);
    AddNotUsedItem(&painting3);
    AddAvailableAction(26, "TakeItemsAction");

    money1.SetKind("money");
    money2.SetKind("money");
    money3.SetKind("money");
    money4.SetKind("money");
    money5.SetKind("money");
    money6.SetKind("money");
    money1.SetPoints(1);
    money2.SetPoints(1);
    money3.SetPoints(1);
    money4.SetPoints(1);
    money5.SetPoints(1);
    money6.SetPoints(1);
    BoundCardWithId(27, &money1);
    BoundCardWithId(28, &money2);
    BoundCardWithId(29, &money3);
    BoundCardWithId(30, &money4);
    BoundCardWithId(31, &money5);
    BoundCardWithId(32, &money6);
    AddNotUsedItem(&money1);
    AddNotUsedItem(&money2);
    AddNotUsedItem(&money3);
    AddNotUsedItem(&money4);
    AddNotUsedItem(&money5);
    AddNotUsedItem(&money6);
    AddAvailableAction(27, "TakeItemsAction");
    AddAvailableAction(28, "TakeItemsAction");
    AddAvailableAction(29, "TakeItemsAction");
    AddAvailableAction(30, "TakeItemsAction");
    AddAvailableAction(31, "TakeItemsAction");
    AddAvailableAction(32, "TakeItemsAction");

    jewelry1.SetKind("jewelry");
    jewelry1.SetPoints(1);
    BoundCardWithId(33, &jewelry1);
    AddNotUsedItem(&jewelry1);
    AddAvailableAction(33, "TakeItemsAction");

    jewelry2.SetKind("jewelry");
    jewelry2.SetPoints(1);
    BoundCardWithId(34, &jewelry2);
    AddNotUsedItem(&jewelry2);
    AddAvailableAction(34, "TakeItemsAction");

    jewelry3.SetKind("jewelry");
    jewelry3.SetPoints(1);
    BoundCardWithId(35, &jewelry3);
    AddNotUsedItem(&jewelry3);
    AddAvailableAction(35, "TakeItemsAction");

    BoundCardWithId(36, &water1);
    BoundCardWithId(37, &water2);
    BoundCardWithId(38, &water3);
    BoundCardWithId(39, &water4);
    BoundCardWithId(40, &water5);
    BoundCardWithId(41, &water6);
    BoundCardWithId(42, &water7);
    BoundCardWithId(43, &water8);
    BoundCardWithId(44, &water9);
    BoundCardWithId(45, &water10);
    BoundCardWithId(46, &water11);
    BoundCardWithId(47, &water12);
    BoundCardWithId(48, &water13);
    BoundCardWithId(49, &water14);
    BoundCardWithId(50, &water15);
    BoundCardWithId(51, &water16);
    BoundCardWithId(52, &water17);
    AddNotUsedItem(&water1);
    AddNotUsedItem(&water2);
    AddNotUsedItem(&water3);
    AddNotUsedItem(&water4);
    AddNotUsedItem(&water5);
    AddNotUsedItem(&water6);
    AddNotUsedItem(&water7);
    AddNotUsedItem(&water8);
    AddNotUsedItem(&water9);
    AddNotUsedItem(&water10);
    AddNotUsedItem(&water11);
    AddNotUsedItem(&water12);
    AddNotUsedItem(&water13);
    AddNotUsedItem(&water14);
    AddNotUsedItem(&water15);
    AddNotUsedItem(&water16);
    AddNotUsedItem(&water17);
    AddAvailableAction(36, "TakeItemsAction");
    AddAvailableAction(37, "TakeItemsAction");
    AddAvailableAction(38, "TakeItemsAction");
    AddAvailableAction(39, "TakeItemsAction");
    AddAvailableAction(40, "TakeItemsAction");
    AddAvailableAction(41, "TakeItemsAction");
    AddAvailableAction(42, "TakeItemsAction");
    AddAvailableAction(43, "TakeItemsAction");
    AddAvailableAction(44, "TakeItemsAction");
    AddAvailableAction(45, "TakeItemsAction");
    AddAvailableAction(46, "TakeItemsAction");
    AddAvailableAction(47, "TakeItemsAction");
    AddAvailableAction(48, "TakeItemsAction");
    AddAvailableAction(49, "TakeItemsAction");
    AddAvailableAction(50, "TakeItemsAction");
    AddAvailableAction(51, "TakeItemsAction");
    AddAvailableAction(52, "TakeItemsAction");

    BoundCardWithId(53, &umbrella);
    AddNotUsedItem(&umbrella);
    AddAvailableAction(53, "TakeItemsAction");

    BoundCardWithId(54, &bait1);
    AddNotUsedItem(&bait1);
    AddAvailableAction(54, "TakeItemsAction");

    BoundCardWithId(55, &bait2);
    AddNotUsedItem(&bait2);
    AddAvailableAction(55, "TakeItemsAction");

    BoundCardWithId(56, &firstAidKit1);
    AddNotUsedItem(&firstAidKit1);
    AddAvailableAction(56, "TakeItemsAction");

    BoundCardWithId(57, &firstAidKit2);
    AddNotUsedItem(&firstAidKit2);
    AddAvailableAction(57, "TakeItemsAction");
    
    BoundCardWithId(58, &firstAidKit3);
    AddNotUsedItem(&firstAidKit3);
    AddAvailableAction(58, "TakeItemsAction");

    BoundCardWithId(59, &lifeline);
    AddNotUsedItem(&lifeline);
    AddAvailableAction(59, "TakeItemsAction");

    BoundCardWithId(60, &compass);
    AddNotUsedItem(&compass);
    AddAvailableAction(60, "TakeItemsAction");

    paddle1.SetPoints(1);
    BoundCardWithId(63, &paddle1);
    AddNotUsedItem(&paddle1);
    AddAvailableAction(63, "TakeItemsAction");

    paddle2.SetPoints(1);
    BoundCardWithId(64, &paddle2);
    AddNotUsedItem(&paddle2);
    AddAvailableAction(64, "TakeItemsAction");

    knife.SetPoints(3);
    BoundCardWithId(65, &knife);
    AddNotUsedItem(&knife);
    AddAvailableAction(65, "TakeItemsAction");

    harpoon.SetPoints(4);
    BoundCardWithId(66, &harpoon);
    AddNotUsedItem(&harpoon);
    AddAvailableAction(66, "TakeItemsAction");

    flareGun.SetPoints(8);
    BoundCardWithId(67, &flareGun);
    AddNotUsedItem(&flareGun);
    AddAvailableAction(67, "TakeItemsAction");

    club.SetPoints(2);
    BoundCardWithId(68, &club);
    AddNotUsedItem(&club);
    AddAvailableAction(68, "TakeItemsAction");

    nav1.SetThirsty({&firstMate});
    nav1.SetOutboard({&firstMate});
    nav1.SetSeagull(0);
    nav1.SetThirstyFighters(0);
    nav1.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav1);
    BoundCardWithId(69, &nav1);
    AddAvailableAction(69, "TakeNavigationCard");

    nav1.SetThirsty({&captain});
    nav1.SetOutboard({&captain});
    nav1.SetSeagull(0);
    nav1.SetThirstyFighters(0);
    nav1.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav1);
    BoundCardWithId(69, &nav1);
    AddAvailableAction(69, "TakeNavigationCard");

    nav2.SetThirsty({&frenchy, &sirStephen});
    nav2.SetOutboard({&drHarter});
    nav2.SetSeagull(0);
    nav2.SetThirstyFighters(0);
    nav2.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav2);
    BoundCardWithId(70, &nav2);
    AddAvailableAction(70, "TakeNavigationCard");

    nav3.SetThirsty({&kid});
    nav3.SetOutboard({&firstMate});
    nav3.SetSeagull(1);
    nav3.SetThirstyFighters(1);
    nav3.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav3);
    BoundCardWithId(71, &nav3);
    AddAvailableAction(71, "TakeNavigationCard");

    nav4.SetThirsty({&firstMate, &captain, &kid});
    nav4.SetOutboard({&frenchy});
    nav4.SetSeagull(0);
    nav4.SetThirstyFighters(0);
    nav4.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav4);
    BoundCardWithId(72, &nav4);
    AddAvailableAction(72, "TakeNavigationCard");

    nav5.SetThirsty({&ladyLauren});
    nav5.SetOutboard({&firstMate});
    nav5.SetSeagull(0);
    nav5.SetThirstyFighters(0);
    nav5.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav5);
    BoundCardWithId(73, &nav5);
    AddAvailableAction(73, "TakeNavigationCard");

    nav6.SetThirsty({&frenchy});
    nav6.SetOutboard({&captain});
    nav6.SetSeagull(0);
    nav6.SetThirstyFighters(0);
    nav6.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav6);
    BoundCardWithId(74, &nav6);
    AddAvailableAction(74, "TakeNavigationCard");

    nav7.SetThirsty({&captain, &frenchy});
    nav7.SetOutboard({&firstMate});
    nav7.SetSeagull(0);
    nav7.SetThirstyFighters(1);
    nav7.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav7);
    BoundCardWithId(75, &nav7);
    AddAvailableAction(75, "TakeNavigationCard");

    nav8.SetThirsty({&firstMate, &captain, &frenchy, &sirStephen});
    nav8.SetOutboard({&frenchy});
    nav8.SetSeagull(0);
    nav8.SetThirstyFighters(1);
    nav8.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav8);
    BoundCardWithId(76, &nav8);
    AddAvailableAction(76, "TakeNavigationCard");

    nav9.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &ladyLauren, &sirStephen, &wong});
    nav9.SetOutboard({&kid});
    nav9.SetSeagull(0);
    nav9.SetThirstyFighters(1);
    nav9.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav9);
    BoundCardWithId(77, &nav9);
    AddAvailableAction(77, "TakeNavigationCard");

    nav10.SetThirsty({&firstMate, &ladyLauren});
    nav10.SetOutboard({&sirStephen});
    nav10.SetSeagull(0);
    nav10.SetThirstyFighters(1);
    nav10.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav10);
    BoundCardWithId(78, &nav10);
    AddAvailableAction(78, "TakeNavigationCard");
    
    nav11.SetThirsty({&firstMate, &captain, &frenchy, &ladyLauren});
    nav11.SetOutboard({&kid});
    nav11.SetSeagull(0);
    nav11.SetThirstyFighters(0);
    nav11.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav11);
    BoundCardWithId(79, &nav11);
    AddAvailableAction(79, "TakeNavigationCard");

    nav12.SetThirsty({&sirStephen});
    nav12.SetOutboard({&captain, &sirStephen});
    nav12.SetSeagull(0);
    nav12.SetThirstyFighters(0);
    nav12.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav12);
    BoundCardWithId(80, &nav12);
    AddAvailableAction(80, "TakeNavigationCard");

    nav13.SetThirsty({&firstMate});
    nav13.SetOutboard({&captain});
    nav13.SetSeagull(1);
    nav13.SetThirstyFighters(1);
    nav13.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav13);
    BoundCardWithId(81, &nav13);
    AddAvailableAction(81, "TakeNavigationCard");

    nav14.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &ladyLauren, &sirStephen, &wong});
    nav14.SetOutboard({&kid});
    nav14.SetSeagull(0);
    nav14.SetThirstyFighters(0);
    nav14.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav14);
    BoundCardWithId(82, &nav14);
    AddAvailableAction(82, "TakeNavigationCard");

    nav15.SetThirsty({&firstMate, &captain});
    nav15.SetOutboard({&drHarter});
    nav15.SetSeagull(1);
    nav15.SetThirstyFighters(1);
    nav15.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav15);
    BoundCardWithId(83, &nav15);
    AddAvailableAction(83, "TakeNavigationCard");

    nav16.SetThirsty({&captain, &drHarter});
    nav16.SetOutboard({&drHarter});
    nav16.SetSeagull(0);
    nav16.SetThirstyFighters(0);
    nav16.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav16);
    BoundCardWithId(84, &nav16);
    AddAvailableAction(84, "TakeNavigationCard");

    nav17.SetThirsty({&captain, &frenchy, &drHarter, &kid, &wong});
    nav17.SetOutboard({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav17.SetSeagull(0);
    nav17.SetThirstyFighters(1);
    nav17.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav17);
    BoundCardWithId(85, &nav17);
    AddAvailableAction(85, "TakeNavigationCard");

    nav18.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &kid, &wong});
    nav18.SetOutboard({&kid});
    nav18.SetSeagull(1);
    nav18.SetThirstyFighters(1);
    nav18.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav18);
    BoundCardWithId(86, &nav18);
    AddAvailableAction(86, "TakeNavigationCard");

    nav19.SetThirsty({&firstMate, &captain, &sirStephen});
    nav19.SetOutboard({&frenchy});
    nav19.SetSeagull(1);
    nav19.SetThirstyFighters(0);
    nav19.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav19);
    BoundCardWithId(87, &nav19);
    AddAvailableAction(87, "TakeNavigationCard");

    nav20.SetThirsty({&firstMate, &drHarter});
    nav20.SetOutboard({&drHarter});
    nav20.SetSeagull(0);
    nav20.SetThirstyFighters(1);
    nav20.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav20);
    BoundCardWithId(88, &nav20);
    AddAvailableAction(88, "TakeNavigationCard");

    nav21.SetThirsty({&firstMate, &captain, &frenchy, &drHarter});
    nav21.SetOutboard({&wong});
    nav21.SetSeagull(1);
    nav21.SetThirstyFighters(0);
    nav21.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav21);
    BoundCardWithId(89, &nav21);
    AddAvailableAction(89, "TakeNavigationCard");

    nav22.SetThirsty({&firstMate, &captain});
    nav22.SetOutboard({&captain});
    nav22.SetSeagull(0);
    nav22.SetThirstyFighters(0);
    nav22.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav22);
    BoundCardWithId(90, &nav22);
    AddAvailableAction(90, "TakeNavigationCard");

    nav23.SetThirsty({&sirStephen});
    nav23.SetOutboard({&captain});
    nav23.SetSeagull(0);
    nav23.SetThirstyFighters(1);
    nav23.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav23);
    BoundCardWithId(91, &nav23);
    AddAvailableAction(91, "TakeNavigationCard");

    nav24.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav24.SetOutboard({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav24.SetSeagull(0);
    nav24.SetThirstyFighters(1);
    nav24.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav24);
    BoundCardWithId(92, &nav24);
    AddAvailableAction(92, "TakeNavigationCard");

    nav25.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav25.SetOutboard({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav25.SetSeagull(1);
    nav25.SetThirstyFighters(1);
    nav25.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav25);
    BoundCardWithId(93, &nav25);
    AddAvailableAction(93, "TakeNavigationCard");

    nav26.SetThirsty({&firstMate, &captain, &ladyLauren});
    nav26.SetOutboard({&frenchy});
    nav26.SetSeagull(0);
    nav26.SetThirstyFighters(1);
    nav26.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav26);
    BoundCardWithId(94, &nav26);
    AddAvailableAction(94, "TakeNavigationCard");

    nav27.SetThirsty({&firstMate, &captain, &frenchy, &drHarter, &kid, &ladyLauren, &sirStephen, &wong});
    nav27.SetOutboard({&ladyLauren});
    nav27.SetSeagull(-1);
    nav27.SetThirstyFighters(0);
    nav27.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav27);
    BoundCardWithId(95, &nav27);
    AddAvailableAction(95, "TakeNavigationCard");

    nav28.SetThirsty({});
    nav28.SetOutboard({});
    nav28.SetSeagull(1);
    nav28.SetThirstyFighters(0);
    nav28.SetThirstyRowers(0);
    AddNotUsedNavigation(&nav28);
    BoundCardWithId(96, &nav28);
    AddAvailableAction(96, "TakeNavigationCard");

    nav29.SetThirsty({&firstMate, &captain, &frenchy});
    nav29.SetOutboard({&sirStephen});
    nav29.SetSeagull(0);
    nav29.SetThirstyFighters(1);
    nav29.SetThirstyRowers(1);
    AddNotUsedNavigation(&nav29);
    BoundCardWithId(97, &nav29);
    AddAvailableAction(97, "TakeNavigationCard");

    for (std::size_t i = 0; i < not_used_items_.size(); i++) {
        int j = rand() % (not_used_items_.size());
        Item* swaped = not_used_items_[i];
        not_used_items_[i] = not_used_items_[j];
        not_used_items_[j] = swaped;
    }

    for (std::size_t i = 0; i < not_used_navigation_cards_.size(); i++) {
        int j = rand() % (not_used_navigation_cards_.size());
        Navigation* swaped = not_used_navigation_cards_[i];
        not_used_navigation_cards_[i] = not_used_navigation_cards_[j];
        not_used_navigation_cards_[j] = swaped;
    }
    
}