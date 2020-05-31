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
    gs.GetCard(98)->RemoveAvailableAction("TakeItemsAction");
    for (std::size_t i = 0; i < gs.GetNumberOfPlayers(); i++) {
        CardPtr card = gs.GetItemCard();
        int id = gs.GetIdCard(card);
        gs.AddToChoice(id);
        card->AddAvailableAction("ChooseItem");
    }
    gs.UpdatePart();
}

void Example::exec(GameState& gs) {
    CharacterPtr c = std::dynamic_pointer_cast<Character>(gs.GetCard(3));
    c->SetHealth(10, gs);
    c->SetExhausted(1, gs);
    c->SetExhausted(0, gs);
    c->SetThirst(1, gs);
}

void TakeNavigationCard::exec(GameState& gs) {
    CardPtr card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
    card->AddAvailableAction("ChooseNavigationCard");
}

void ChooseCharacterCard::exec(GameState& gs) {
    gs.SetLast(player_);
    gs.AddPlayerCharacter(player_, id_);
    gs.GetChosen(id_);
}

void ChooseItem::exec(GameState& gs) {
    gs.SetLast(player_);
    ItemPtr item = std::dynamic_pointer_cast<Item>(gs.GetCard(id_));
    PlayerPtr current_player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr character = current_player->GetCharacter();
    character->AddItem(item, gs);
    gs.GetChosen(id_);
    // item->RemoveAvailableAction("ChooseItem");
    // item->RemoveAvailableAction("ChooseItem");
    // gs.UpdatePart();
    
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
            character->SetThirst(true, gs);
            character->UpdateState(gs);
        }
    }
    if (current_navigation->GetThirstyRowers()) {
        for (std::size_t i = 0; i < gs.GetSizeOfRowed(); i++) {
            CharacterPtr character = gs.GetRowed(i);
            character->SetThirst(true, gs);
            character->UpdateState(gs);
        }
    }
    for (std::size_t i = 0; i < current_navigation->GetOutboardSize(); i++) {
        CharacterPtr character = current_navigation->GetOutboard(i);
        character->SetWounds(character->GetWounds() + 1);
        character->SetHealth(character->GetHealth() - 100 / character->GetStrength(), gs);
        character->UpdateState(gs);
        gs.AddCardOutboard(character);
    }
    for (std::size_t i = 0; i < current_navigation->GetThirstySize(); i++) {
        CharacterPtr character = current_navigation->GetThirsty(i);
        character->SetThirst(true, gs);
        character->UpdateState(gs);
    }
    gs.FinishRound();
    gs.UpdatePart();
}

void Row::exec(GameState& gs) {
    for (std::size_t i = 0; i < 2; i++) {
        TakeNavigationCard take(player_, id_, other_card_);
        take.exec(gs);
    }
    PlayerPtr current_player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr character = current_player->GetCharacter();
    gs.AddCardRowed(character);
    character->SetExhausted(true, gs);
    gs.UpdatePart();
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