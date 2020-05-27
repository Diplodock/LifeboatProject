#include "game_state.h"

#include <cassert>

#include "goods.h"
#include "universal.h"

extern std::vector<CharacterPtr> list;
extern std::vector<PlayerPtr> listPlayer;
extern std::vector<AddPtr> listAdditional;
extern std::vector<ItemPtr> listWeapon, listUni, listGoods;
extern std::vector<NavigationPtr> listNav;



int GameState::GetChosenNav() const {
    return current_choice_[0];
}

int GameState::GetSizeUnusedNavigation() const {
    return not_used_navigation_cards_.size();
}

int GameState::GetNumberOfSeagulls() const {
    return number_of_seagulls_;
}

int GameState::GetNumberOfPlayers() const {
    return number_of_players_;
}

NavigationPtr GameState::GetNavigationCard() {
    assert(not_used_navigation_cards_.size() > 0);
    NavigationPtr current_card_ = not_used_navigation_cards_[0];
    not_used_navigation_cards_.pop_front();
    return current_card_;
 }

ItemPtr GameState::GetItemCard() {
    assert(not_used_items_.size() > 0);
    ItemPtr current_card_ = not_used_items_[0];
    not_used_items_.pop_front();
    return current_card_;
}

int GameState::GetIdCard(CardPtr card) {
    return get_id_using_card_[card];
}

CardPtr GameState::GetCard(int id) {
    return get_card_using_id_[id];
}

PlayerPtr GameState::GetPlayerUsingPlayerId(int id) {
    return get_player_[id];
}

 int GameState::GetSizeOfOutboard() const {
    return outboard_.size();
 }

CharacterPtr GameState::GetCharacterOutboard(std::size_t i) const {
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

CharacterPtr GameState::GetFought(std::size_t index) const {
    return fought_[index];
}

CharacterPtr GameState::GetRowed(std::size_t index) const {
    return rowed_[index];
}

std::size_t GameState::GetSizeOfFought() const {
    return fought_.size();
}

std::size_t GameState::GetSizeOfRowed() const {
    return rowed_.size();
}

std::vector<std::string> GameState::GetAvailableActions() {
    return available_actions_[round_];
}

void GameState::SetNumberOfSeagulls(int number_of_seagulls) {
    for (auto x : sListeners) {
        x->notify(number_of_seagulls);
    }
    number_of_seagulls_ = number_of_seagulls;
}

void GameState::AddCardFought(CharacterPtr current_character) {
    fought_.push_back(current_character);
}

void GameState::AddCardRowed(CharacterPtr current_character) {
    rowed_.push_back(current_character);
}

void GameState::AddCardOutboard(CharacterPtr current_character) {
    for (auto x : oListeners) {
        x->notify(get_id_using_card_[current_character]);
    }
    outboard_.push_back(current_character);
}

void GameState::AddNotUsedNavigation(NavigationPtr current_navigation) {
    not_used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddTheRestNavigation() {
    for (auto x : remNotUsedListeners) {
        x->notify(current_choice_);
    }
    for (std::size_t i = 0; i < current_choice_.size(); i++) {
        NavigationPtr current_navigation = std::dynamic_pointer_cast<Navigation>(get_card_using_id_[current_choice_[i]]);
        not_used_navigation_cards_.push_back(current_navigation);
        get_card_using_id_[current_choice_[i]]->RemoveAvailableAction("ChooseNavigationCard");
    }
}

void GameState::AddNotUsedItem(ItemPtr current_item) {
    not_used_items_.push_back(current_item);
}

void GameState::AddUsedNavigation(NavigationPtr current_navigation) {
    for (auto x : remUsedListeners) {
        x->notify(get_id_using_card_[current_navigation]);
    }
    used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddChosenNavigation(int id) {
    chosen_navigation_card_ = id;
}

void GameState::AddUsedItem(ItemPtr current_item) {
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
    CharacterPtr current_character = std::dynamic_pointer_cast<Character>(get_card_using_id_[id]); 
    get_character_id_using_player_.push_back(current_character);
    get_player_using_character_id_[current_character] = player;
}

void GameState::AddCharacter(CharacterPtr character) {
    characters_.push_back(character);
}

void GameState::BoundCardWithId(int id, CardPtr card) {
    get_id_using_card_[card] = id;
    get_card_using_id_[id] = card;
}

void GameState::SetPlayer(PlayerPtr player) {
    get_player_.push_back(player);
}

void GameState::SetLast(int player) {
    last_player_ = player;
}

void GameState::AddAvailableAction(std::string action, int round) {
    available_actions_[round].push_back(action);
}

void GameState::RemoveAvailableAction(std::string action, int round) {
    std::size_t j = 0;
    for (; j < available_actions_[round].size(); j++) {
        if (available_actions_[round][j] == action) {
            break;
        }
    }
    for (; j < available_actions_[round].size() - 1; j++) {
        available_actions_[round][j] = available_actions_[round][j + 1]; 
    }
}

void GameState::FinishRound() {
    fought_.clear();
    rowed_.clear();
    outboard_.clear();
    current_choice_.clear();
}

void GameState::UpdatePart() {
    if (last_player_ == number_of_players_ - 1) {
        round_ = (round_ + 1) % 4; 
        last_player_ = 0;
    }
}

std::vector<std::string> GameState::GetAvailableActions(int id, int player) {
    return get_card_using_id_[id]->GetAvailableActions(player, *this);
}


int GameState::GetSizeOfChoice() const {
    return current_choice_.size();
}

GameState::GameState(std::size_t number_of_players)
    : number_of_players_(number_of_players)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());

    available_actions_.resize(4, std::vector<std::string>());

    std::vector<std::string> listAction =
     {"TryToSwap",
     "TryToTakeGoods",
     "TryToGiveGoods",
     "Fight"};

    for (std::size_t i = 0; i < 8; i++) {
        AddCharacter(list[0]);
        BoundCardWithId(i, list[i]);
        for (std::size_t j = 0; j < 4; j++) {
            get_card_using_id_[i]->AddAvailableAction(listAction[j]);
        }
    }

    std::vector<CharacterPtr> randCharacters = characters_;
    for (std::size_t i = 0; i < characters_.size(); i++) {
        srand(time(0));
        int j = mersenne() % (characters_.size());
        CharacterPtr swaped = randCharacters[i];
        randCharacters[i] = randCharacters[j];
        randCharacters[j] = swaped;
    }

    for (std::size_t i = 0; i < 8; i++) {
        SetPlayer(listPlayer[i]);
        listPlayer[i]->SetCharacter(randCharacters[i]);
        AddPlayerCharacter(i, get_id_using_card_[listPlayer[i]->GetCharacter()]);
    }

    std::vector<std::pair<std::string, int>> listAdd =
    {{"painting", 3}, {"painting", 2}, {"painting", 3},
    {"money", 1}, {"jewelry", 1}
    };

    for (std::size_t i = 0, j = 0, k = 24; i < 12; i++, k++) {
        listAdditional[i]->SetKind(listAdd[j].first);
        listAdditional[i]->SetPoints(listAdd[j].second);
        if (i < 2) {
            j++;
        }
        else if (i == 2) {
            j = 3;
        }
        else if (i == 8) {
            j = 4;
        }
        BoundCardWithId(k, listAdditional[i]);
        AddNotUsedItem(listAdditional[i]);
        get_card_using_id_[k]->AddAvailableAction("TakeItemsAction");
    }

    std::vector<int> listDamages = {1, 1, 8, 4, 3, 2};

    for (std::size_t i = 0, j = 36; i < 25; i++, j++) {
        BoundCardWithId(j, listGoods[i]);
        AddNotUsedItem(listGoods[i]);
        get_card_using_id_[j]->AddAvailableAction("TakeItemsAction");
    }
    
    for (std::size_t i = 0, j = 63; i < 3; i++, j++) {
        listUni[i]->SetPoints(listDamages[i]);
        BoundCardWithId(j, listUni[i]);
        AddNotUsedItem(listUni[i]);
        get_card_using_id_[j]->AddAvailableAction("TakeItemsAction");

    }

    for (std::size_t i = 3, j = 66, k = 0; i < 6; i++, j++, k++) {
        listWeapon[k]->SetPoints(listDamages[i]);
        BoundCardWithId(j, listWeapon[k]);
        AddNotUsedItem(listWeapon[k]);
        get_card_using_id_[j]->AddAvailableAction("TakeItemsAction");
    }

    std::vector<std::vector<CharacterPtr>> listThirsty =
    {{list[1]}, {list[2], list[6]}, {list[4]}, {list[0], list[1], list[4]},
    {list[5]}, {list[2]}, {list[1], list[2]}, {list[0], list[1], list[2], list[6]},
    {list[0], list[1], list[2], list[3], list[5], list[6], list[7]},
    {list[0], list[5]}, {list[0], list[1], list[2], list[5]}, {list[6]},
    {list[0]}, {list[0], list[1], list[2], list[3], list[5], list[6], list[7]},
    {list[0], list[1]}, {list[1], list[3]}, {list[1], list[2], list[3], list[4], list[7]},
    {list[0], list[1], list[2], list[3], list[4], list[7]}, {list[0], list[1], list[6]},
    {list[0], list[3]}, {list[0], list[1], list[2], list[3]}, {list[0], list[1]},
    {list[6]}, {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]},
    {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]}, 
    {list[0], list[1], list[5]}, 
    {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]}, {},
    {list[0], list[1], list[2]}};

    std::vector<std::vector<CharacterPtr>> listOutboard =
    {{list[1]}, {list[3]}, {list[0]}, {list[2]}, {list[0]},
    {list[1]}, {list[0]}, {list[2]}, {list[4]}, {list[6]},
    {list[4]}, {list[1], list[6]}, {list[1]}, {list[4]},
    {list[3]}, {list[3]}, 
    {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]},
    {list[4]}, {list[2]}, {list[3]}, {list[7]}, {list[1]}, {list[1]},
    {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]},
    {list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7]},
    {list[2]}, {list[5]}, {}, {list[6]}};

    std::vector<int> listSeagull = 
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1,
    0, 0, 0, 1, 0, -1, 1, 0};
    std::vector<std::pair<bool, bool>> thirstyFightersRowers = 
    {{0, 0}, {0, 0}, {1, 0}, {0, 1}, {0, 0}, {0, 0}, {1, 1}, {1, 1},
    {1, 0}, {1, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 1}, {1, 1}, {0, 1},
    {1, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0},
    {1, 1}, {1, 0}, {0, 1}, {0, 0}, {1, 1}};

    for (std::size_t i = 0, j = 69; i < 29; i++, j++) {
        listNav[i]->SetThirsty(listThirsty[i]);
        listNav[i]->SetOutboard(listOutboard[i]);
        listNav[i]->SetSeagull(listSeagull[i]);
        listNav[i]->SetThirstyFighters(thirstyFightersRowers[i].first);
        listNav[i]->SetThirstyRowers(thirstyFightersRowers[i].second);
        AddNotUsedNavigation(listNav[i]);
        BoundCardWithId(j, listNav[i]);
        get_card_using_id_[j]->AddAvailableAction("TakeNavigationCard");
    }

    for (std::size_t i = 0; i < not_used_items_.size(); i++) {
        int j = mersenne() % (not_used_items_.size());
        ItemPtr swaped = not_used_items_[i];
        not_used_items_[i] = not_used_items_[j];
        not_used_items_[j] = swaped;
    }

    for (std::size_t i = 0; i < not_used_navigation_cards_.size(); i++) {
        srand(time(0));
        int j = mersenne() % (not_used_navigation_cards_.size());
        NavigationPtr swaped = not_used_navigation_cards_[i];
        not_used_navigation_cards_[i] = not_used_navigation_cards_[j];
        not_used_navigation_cards_[j] = swaped;
    }
    
}

void GameState::AddSListener(std::shared_ptr<SeagullsListener> l) {
    sListeners.push_back(l);
}
void GameState::AddAddListener(std::shared_ptr<AddCardsOnBoardListener> l) {
    addListeners.push_back(l);
}
void GameState::AddRemUsedListener(std::shared_ptr<RemoveUsedCardListener> l) {
    remUsedListeners.push_back(l);
}
void GameState::AddRemNotUsedListener(std::shared_ptr<RemoveNotUsedCardsListener> l) {
    remNotUsedListeners.push_back(l);
}
void GameState::AddEListener(std::shared_ptr<ExhaustedListener> l) {
    eListeners.push_back(l);
}
void GameState::AddDListener(std::shared_ptr<DeathListener> l) {
    dListeners.push_back(l);
}
void GameState::AddTListener(std::shared_ptr<ThirstListener> l) {
    tListeners.push_back(l);
}
void GameState::AddOListener(std::shared_ptr<OutboardListener> l) {
    oListeners.push_back(l);
}
void GameState::AddTuListener(std::shared_ptr<TurnListener> l) {
    tuListeners.push_back(l);
}