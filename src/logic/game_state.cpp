#include "game_state.h"

#include <cassert>

#include "goods.h"
#include "universal.h"

extern std::vector<CharacterPtr> list;
extern std::vector<PlayerPtr> listPlayer;
extern std::vector<AddPtr> listAdditional;
extern std::vector<ItemPtr> listWeapon, listUni, listGoods;
extern std::vector<NavigationPtr> listNav;

static Card supplies;
static Card navigation;
static Card button;

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
    if (number_of_seagulls - number_of_seagulls_ == 1) {
        for (auto x : sListeners) {
            x->notify();
        }
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
        current_navigation->RemoveAvailableAction("ChooseNavigationCard");
        not_used_navigation_cards_.push_back(current_navigation);
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
    get_player_[player]->SetCharacter(current_character);
}

void GameState::AddCharacter(CharacterPtr character) {
    characters_.push_back(character);
}

void GameState::BoundCardWithId(int id, CardPtr card) {
    card->SetId(id);
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

void GameState::NotifyHealth(int id, int points) {
    for (auto x : hListeners) {
        x->notify(id, points);
    }
}

void GameState::NotifyExhausted(int id, bool is) {
    for (auto x : eListeners) {
        x->notify(id,is);
    }
}

void GameState::NotifyThirst(int id, bool is) {
    for (auto x : tListeners) {
        x->notify(id, is);
    }
}

void GameState::NotifyUmbrella(int id, bool is) {
    for (auto x : uListeners) {
        x->notify(id, is);
    }
}

void GameState::NotifyOwner(int id, int card) {
    for (auto x : ownListeners) {
        x->notify(id, card);
    }
}

void GameState::NotifyUsed(int id) {
    for (auto x : remUsedListeners) {
        x->notify(id);
    }
}

std::vector<int> GameState::GetBackpack(int id) {
    CharacterPtr character = std::dynamic_pointer_cast<Character>(GetCard(id));
    std::vector<ItemPtr> items = character->GetCharBackpack();
    std::vector<int> cur;
    for (auto x : items) {
        cur.push_back(GetIdCard(x));
    }
    return cur;
}

void GameState::FinishRound() {
    fought_.clear();
    rowed_.clear();
    outboard_.clear();
    current_choice_.clear();
}

int GameState::GetTurn() {
    return turn_;
}

void GameState::UpdatePart() {
    if (round_ == 0) {
        round_++;
        for (auto x : roundListeners) {
            x->notify(rounds_[1]);
        }
        for (auto x : tuListeners) {
            x->notify(characters_[0]->GetId(), characters_[0]->GetId());
        }
    }
    else if (round_ == 1) {
        if (turn_ < 5) {
            for (auto x : tuListeners) {
                x->notify(characters_[turn_]->GetId(), characters_[(turn_ + 1) % 6]->GetId());
            }
            turn_++;
        }
        else {
            for (auto x : tuListeners) {
                x->notify(characters_[turn_]->GetId(), characters_[(turn_ + 1) % 6]->GetId());
            }
            for (auto x : roundListeners) {
                x->notify(rounds_[2]);
            }
            round_++;
            GetCard(104)->AddAvailableAction("Row");
            GetCard(104)->AddAvailableAction("Skip");
            turn_ = 0;
        }
    }
    else if (round_ == 2) {
        if (turn_ < 5) {
            for (auto x : tuListeners) {
                x->notify(characters_[turn_]->GetId(), characters_[(turn_ + 1) % 6]->GetId());
            }
            turn_++;
        }
        else {
            for (auto x : tuListeners) {
                x->notify(characters_[turn_]->GetId(), characters_[(turn_ + 1) % 6]->GetId());
            }
            round_++;
            GetCard(104)->RemoveAvailableAction("Row");
            GetCard(104)->RemoveAvailableAction("Skip");
            for (auto x : current_choice_) {
                GetCard(x)->AddAvailableAction("ChooseNavigationCard");
            }
            for (auto x : roundListeners) {
                x->notify(rounds_[3]);
            }
            turn_ = 0;
        }
    }
    else {
        round_ = 0;
        GetCard(98)->AddAvailableAction("TakeItemsAction");
        for (auto x : roundListeners) {
            x->notify(rounds_[0]);
        }
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

    available_actions_.resize(8, std::vector<std::string>());

    std::vector<std::string> listAction =
    {
     "Example"
    };

    std::vector<int> list2 = {5, 1, 2, 0, 6, 4};

    for (std::size_t i = 0; i < 6; i++) {
        AddCharacter(list[i]);
        BoundCardWithId(list2[i], list[i]);
        get_card_using_id_[list2[i]]->AddAvailableAction(listAction[0]);
    }

    for (std::size_t i = 0; i < 6; i++) {
        SetPlayer(listPlayer[i]);
        AddPlayerCharacter(i, GetIdCard(list[i]));
        listPlayer[i]->SetCharacter(list[i]);
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
    }

    std::vector<int> listDamages = {1, 1, 8, 4, 3, 2};

    for (std::size_t i = 0, j = 36; i < 25; i++, j++) {
        BoundCardWithId(j, listGoods[i]);
        AddNotUsedItem(listGoods[i]);
    }
    
    for (std::size_t i = 0, j = 63; i < 3; i++, j++) {
        listUni[i]->SetPoints(listDamages[i]);
        BoundCardWithId(j, listUni[i]);
        AddNotUsedItem(listUni[i]);

    }

    for (std::size_t i = 3, j = 66, k = 0; i < 6; i++, j++, k++) {
        listWeapon[k]->SetPoints(listDamages[i]);
        BoundCardWithId(j, listWeapon[k]);
        AddNotUsedItem(listWeapon[k]);
    }

    std::vector<std::vector<CharacterPtr>> listThirsty =
    {{list[1]}, {list[2], list[4]}, {list[5]}, {list[3], list[1], list[5]},
    {list[0]}, {list[2]}, {list[1], list[2]}, {list[3], list[1], list[2], list[4]},
    {list[3], list[1], list[2], list[0], list[4], },
    {list[3], list[0]}, {list[3], list[1], list[2], list[0]}, {list[4]},
    {list[3]}, {list[3], list[1], list[2], list[0], list[4], },
    {list[3], list[1]}, {list[1], }, {list[1], list[2], list[5], },
    {list[3], list[1], list[2], list[5], }, {list[3], list[1], list[4]},
    {list[3], }, {list[3], list[1], list[2], }, {list[3], list[1]},
    {list[4]}, {list[3], list[1], list[2], list[5], list[0], list[4], },
    {list[3], list[1], list[2], list[5], list[0], list[4], }, 
    {list[3], list[1], list[0]}, 
    {list[3], list[1], list[2], list[5], list[0], list[4], }, {},
    {list[3], list[1], list[2]}};

    std::vector<std::vector<CharacterPtr>> listOutboard =
    {{list[1]}, {}, {list[3]}, {list[2]}, {list[3]},
    {list[1]}, {list[3]}, {list[2]}, {list[5]}, {list[4]},
    {list[5]}, {list[1], list[4]}, {list[1]}, {list[5]},
    {}, {}, 
    {list[3], list[1], list[2], list[5], list[0], list[4], },
    {list[5]}, {list[2]}, {}, {}, {list[1]}, {list[1]},
    {list[3], list[1], list[2], list[5], list[0], list[4], },
    {list[3], list[1], list[2], list[5], list[0], list[4], },
    {list[2]}, {list[0]}, {}, {list[4]}};

    std::vector<int> listSeagull = 
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1,
    0, 0, 0, 1, 0, 1, 1, 0};
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
    supplies.AddAvailableAction("TakeItemsAction");
    // navigation.AddAvailableAction("TakeNavigationCard");
    // button.AddAvailableAction("Row");
    // button.AddAvailableAction("Skip");
    BoundCardWithId(98, std::make_shared<Card>(supplies));
    BoundCardWithId(99, std::make_shared<Card>(navigation));
    BoundCardWithId(104, std::make_shared<Card>(button));
 
    
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
void GameState::AddHealthListener(std::shared_ptr<HealthListener> l) {
    hListeners.push_back(l);
}
void GameState::AddUmbrellaListener(std::shared_ptr<UmbrellaListener> l) {
    uListeners.push_back(l);
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
void GameState::AddOwnerListener(std::shared_ptr<OwnerListener> l) {
    ownListeners.push_back(l);
}
void GameState::AddRoundListener(std::shared_ptr<RoundListener> l) {
    roundListeners.push_back(l);
}