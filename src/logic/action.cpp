#include "action.h"

#include <iostream>

#include "game_state.h"
#include "character.h"
#include "item.h"
#include <memory>

void TakeItemsAction::exec(GameState& gs) {
    for (std::size_t i = 0; i < gs.GetNumberOfPlayers(); i++) {
        Card* card = gs.GetItemCard();
        int id = gs.GetIdCard(card);
        gs.AddToChoice(id);
    }
};

void TakeNavigationCard::exec(GameState& gs) {
    Card* card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
}

ChooseCharacterCard::ChooseCharacterCard(int player, int id) {
    player_ = player;
    id_ = id;
}

void ChooseCharacterCard::exec(GameState& gs) {
    gs.AddPlayerCharacter(player_, id_);
    gs.GetChosen(id_);
}

ChooseItem::ChooseItem(int player, int id) {
    player_ = player;
    id_ = id;
}

void ChooseItem::exec(GameState& gs) {
    Item* item = dynamic_cast<Item *> (gs.GetCard(id_));
    Player* current_player = gs.GetPlayerUsingPlayerId(player_);
    Character* character = current_player->GetCharacter();
    character->AddItem(item);
    gs.GetChosen(id_);
}

ChooseNavigationCard::ChooseNavigationCard(int player, int id) {
    player_ = player;
    id_ = id;
}

void ChooseNavigationCard::exec(GameState& gs) {
    gs.GetChosen(id_);
    gs.AddChosenNavigation(id_);
    gs.AddTheRestNavigation();
    Navigation* current_navigation = dynamic_cast<Navigation*> (gs.GetCard(id_));
    int current_number_of_seagulls = gs.GetNumberOfSeagulls();
    gs.SetNumberOfSeagulls(current_number_of_seagulls + current_navigation->GetSeagull());
    if (current_navigation->GetThirstyFighters()) {
        for (std::size_t i = 0; i < gs.GetSizeOfFought(); i++) {
            Character* character = gs.GetFought(i);
            character->SetThirst(true);
            character->UpdateState();
        }
    }
    if (current_navigation->GetThirstyRowers()) {
        for (std::size_t i = 0; i < gs.GetSizeOfRowed(); i++) {
            Character* character = gs.GetRowed(i);
            character->SetThirst(true);
            character->UpdateState();
        }
    }
    for (std::size_t i = 0; i < current_navigation->GetOutboardSize(); i++) {
        Character* character = current_navigation->GetOutboard(i);
        character->SetWounds(character->GetWounds() + 1);
        character->SetHealth(character->GetHealth() - 100 / character->GetStrength());
        character->UpdateState();
        gs.AddCardOutboard(character);
    }
    for (std::size_t i = 0; i < current_navigation->GetThirstySize(); i++) {
        Character* character = current_navigation->GetThirsty(i);
        character->SetThirst(true);
        character->UpdateState();
    }
    gs.FinishRound();
}

Row::Row(int player) {
    player_ = player;
}

void Row::exec(GameState& gs) {
    for (std::size_t i = 0; i < 2; i++) {
        TakeNavigationCard();
    }
    Player* current_player = gs.GetPlayerUsingPlayerId(player_);
    Character* character = current_player->GetCharacter();
    gs.AddCardRowed(character);
    character->SetExhausted(true);
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

std::unique_ptr<GenericAction> O(ChooseCharacterCard act) {
    return std::make_unique<ChooseCharacterCard>(&act);
}