#include "goods.h"

void Water::WaterCardAction::exec(GameState& gs) {
    Player* player = gs.GetPlayerUsingPlayerId(this->player_);
    player->GetCharacter()->SetThirst(false);
}

// std::unique_ptr<GenericAction> Water::GetAction(int player) {
//     return std::make_unique<WaterCardAction>(this, player);
// }

void Umbrella::UmbrellaCardAction::exec(GameState& gs) {
    Player* player = gs.GetPlayerUsingPlayerId(this->player_);
    player->GetCharacter()->HoldUmbrella(true);
}

// std::unique_ptr<GenericAction> Umbrella::GetAction(int player)  {
//     return std::make_unique<UmbrellaCardAction>(this, player);
// }

void FirstAidKit::FirstAidKitCardAction::exec(GameState& gs) {
    Player* saved = gs.GetPlayerUsingPlayerId(this->other_card_);
    saved->GetCharacter()->SetWounds(saved->GetCharacter()->GetWounds() - 1);
}

// std::unique_ptr<GenericAction> FirstAidKit::GetAction(int player, int saved)  {
//     return std::make_unique<FirstAidKitCardAction>(this, player, saved);
// }

void Compass::CompassCardAction::exec(GameState& gs) {
    Card* card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
}

// std::unique_ptr<GenericAction> Compass::GetAction()  {
//     return std::make_unique<CompassCardAction>(this);
// }

void Bait::BaitCardAction::exec(GameState& gs) {
    std::size_t current_size = gs.GetSizeOfOutboard();
    for (std::size_t i = 0; i < current_size; i++) {
        Character* outboard_character = gs.GetCharacterOutboard(i);
        outboard_character->SetWounds(outboard_character->GetWounds() + 1);
    }
}

// std::unique_ptr<GenericAction> Bait::GetAction()  {
//     return std::make_unique<BaitCardAction>(this);
// }

void Lifeline::LifelineCardAction::exec(GameState& gs) {
    Player* saved = gs.GetPlayerUsingPlayerId(this->other_card_);
    saved->GetCharacter()->SetWounds(saved->GetCharacter()->GetWounds() - 1);
}

// std::unique_ptr<GenericAction> Lifeline::GetAction(int player, int saved)  {
//     return std::make_unique<LifelineCardAction>(this, player, saved);
// }