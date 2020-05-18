#include "action.h"

#include <iostream>

#include "game_state.h"
#include "character.h"
#include "item.h"
#include <memory>

GenericAction::GenericAction(int player, int id, int other_card)
    : player_(player), id_(id), other_card_(other_card) {}

int GenericAction::GetPlayer() {
    return player_;
}

int GenericAction::GetId() {
    return id_;
}

void TakeItemsAction::exec(GameState& gs) {
    for (std::size_t i = 0; i < gs.GetNumberOfPlayers(); i++) {
        CardPtr card = gs.GetItemCard();
        int id = gs.GetIdCard(card);
        gs.AddToChoice(id);
        card->RemoveAvailableAction("TakeItemsAction");
        card->AddAvailableAction("ChooseItem");
    }
}

void TakeNavigationCard::exec(GameState& gs) {
    CardPtr card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
    card->RemoveAvailableAction("TakeNavigationCard");
    card->AddAvailableAction("ChooseNavigationCard");
}

void ChooseCharacterCard::exec(GameState& gs) {
    gs.AddPlayerCharacter(player_, id_);
    gs.GetChosen(id_);
}

void ChooseItem::exec(GameState& gs) {
    ItemPtr item = std::dynamic_pointer_cast<Item>(gs.GetCard(id_));
    PlayerPtr current_player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr character = current_player->GetCharacter();
    character->AddItem(item);
    gs.GetChosen(id_);
    item->RemoveAvailableAction("ChooseItem");
}

void ChooseNavigationCard::exec(GameState& gs) {
    NavigationPtr nav = std::dynamic_pointer_cast<Navigation>(gs.GetCard(id_));
    gs.GetChosen(id_);
    nav->RemoveAvailableAction("ChooseNavigationCard");
    gs.AddChosenNavigation(id_);
    gs.AddTheRestNavigation();
    NavigationPtr current_navigation = std::dynamic_pointer_cast<Navigation> (gs.GetCard(id_));
    int current_number_of_seagulls = gs.GetNumberOfSeagulls();
    gs.SetNumberOfSeagulls(current_number_of_seagulls + current_navigation->GetSeagull());
    if (current_navigation->GetThirstyFighters()) {
        for (std::size_t i = 0; i < gs.GetSizeOfFought(); i++) {
            CharacterPtr character = gs.GetFought(i);
            character->SetThirst(true);
            character->UpdateState();
        }
    }
    if (current_navigation->GetThirstyRowers()) {
        for (std::size_t i = 0; i < gs.GetSizeOfRowed(); i++) {
            CharacterPtr character = gs.GetRowed(i);
            character->SetThirst(true);
            character->UpdateState();
        }
    }
    for (std::size_t i = 0; i < current_navigation->GetOutboardSize(); i++) {
        CharacterPtr character = current_navigation->GetOutboard(i);
        character->SetWounds(character->GetWounds() + 1);
        character->SetHealth(character->GetHealth() - 100 / character->GetStrength());
        character->UpdateState();
        gs.AddCardOutboard(character);
    }
    for (std::size_t i = 0; i < current_navigation->GetThirstySize(); i++) {
        CharacterPtr character = current_navigation->GetThirsty(i);
        character->SetThirst(true);
        character->UpdateState();
    }
    gs.FinishRound();
}

void Row::exec(GameState& gs) {
    for (std::size_t i = 0; i < 2; i++) {
        TakeNavigationCard take(player_, id_, other_card_);
        take.exec(gs);
    }
    PlayerPtr current_player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr character = current_player->GetCharacter();
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

// std::unique_ptr<GenericAction> O(ChooseCharacterCard act) {
//     return std::make_unique<ChooseCharacterCard>(&act);
// }