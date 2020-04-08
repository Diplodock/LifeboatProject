#include "action.h"

Action::Action(GameState* game_state)
    :game_state_(game_state) {};

void Action::ChooseCharacterCard(int player, int id) {
    (*game_state_).AddPlayerCharacter(player, id);
    (*game_state_).GetChosen(id);
}

void Action::TakeItems() {
    for (std::size_t i = 0; i < 6; i++) {
        Card* card = (*game_state_).GetItemCard();
        int id = (*game_state_).GetIdCard(card);
        (*game_state_).AddToChoice(id);
    }
}

void Action::TakeNavigationCard() {
    Card* card = (*game_state_).GetNavigationCard();
    int id = (*game_state_).GetIdCard(card);
    (*game_state_).AddToChoice(id);
}

void Action::ChooseItem(int player, int id) {
    Item* item = dynamic_cast<Item *> ((*game_state_).GetCard(id));
    Player* current_player = (*game_state_).GetPlayerUsingPlayerId(player);
    Character* character = (*current_player).GetCharacter();
    (*character).AddItem(item);
    (*game_state_).GetChosen(id);
}

void Action::ChooseNavigationCard(int player, int id) {
    (*game_state_).GetChosen(id);
    (*game_state_).AddChosenNavigation(id);
    (*game_state_).AddTheRestNavigation();
    Navigation* current_navigation = dynamic_cast<Navigation*> ((*game_state_).GetCard(id));
    int current_number_of_seagulls = (*game_state_).GetNumberOfSeagulls();
    (*game_state_).SetNumberOfSeagulls(current_number_of_seagulls + (*current_navigation).GetSeagull());
    if ((*current_navigation).GetThirstyFighters()) {
        for (std::size_t i = 0; i < (*game_state_).GetSizeOfFought(); i++) {
            Character* character = (*game_state_).GetFought(i);
            (*character).SetThirst(true);
            (*character).UpdateState();
        }
    }
    if ((*current_navigation).GetThirstyRowers()) {
        for (std::size_t i = 0; i < (*game_state_).GetSizeOfRowed(); i++) {
            Character* character = (*game_state_).GetRowed(i);
            (*character).SetThirst(true);
            (*character).UpdateState();
        }
    }
    for (std::size_t i = 0; i < (*current_navigation).GetOutboardSize(); i++) {
        Character* character = (*current_navigation).GetOutboard(i);
        (*character).SetWounds((*character).GetWounds() + 1); 
        (*character).UpdateState();
        (*game_state_).AddCardOutboard(character);
    }
    for (std::size_t i = 0; i < (*current_navigation).GetThirstySize(); i++) {
        Character* character = (*current_navigation).GetThirsty(i);
        (*character).SetThirst(true);
        (*character).UpdateState();
    }
    (*game_state_).FinishRound();
}

void Action::Row(int player) {
    for (std::size_t i = 0; i < 2; i++) {
        TakeNavigationCard();
    }
    Player* current_player = (*game_state_).GetPlayerUsingPlayerId(player);
    Character* character = (*current_player).GetCharacter();
    (*game_state_).AddCardRowed(character);
    (*character).SetExhausted(true);
}

// bool Character::Fight(Character* target) { // TODO: add ally support and weapon
//     characterOptions_.exhausted = true;
//     (*target).characterOptions_.exhausted = true;
//     if (characterOptions_.strength > (*target).characterOptions_.strength) {
//         (*target).characterOptions_.health -= 100 / (*target).characterOptions_.strength;
//         return true;
//     }
//     else {
//         characterOptions_.health -= 100 / characterOptions_.strength;
//         return false;
//     }
// }