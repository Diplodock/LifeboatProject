#include "goods.h"

Water::WaterCardAction::WaterCardAction(Water* owner, int player)
    : owner_(owner)
    {
        owner->SetPlayer(player);
    }

void Water::WaterCardAction::exec(GameState& gs) {
    Player* player = gs.GetPlayerUsingPlayerId(this->player_);
    player->GetCharacter()->SetThirst(false);
}

std::unique_ptr<GenericAction> Water::GetAction(int player) {
    return std::make_unique<WaterCardAction>(this, player);
}

Umbrella::UmbrellaCardAction::UmbrellaCardAction(Umbrella* owner, int player)
    : owner_(owner)
    {
        owner->SetPlayer(player);
    }

void Umbrella::UmbrellaCardAction::exec(GameState& gs) {
    Player* player = gs.GetPlayerUsingPlayerId(this->player_);
    player->GetCharacter()->HoldUmbrella(true);
}

std::unique_ptr<GenericAction> Umbrella::GetAction(int player)  {
    return std::make_unique<UmbrellaCardAction>(this, player);
}

FirstAidKit::FirstAidKitCardAction::FirstAidKitCardAction(FirstAidKit* owner, int player, int saved)
    : owner_(owner), saved_(saved)
    {
        owner->SetPlayer(player);
    }

void FirstAidKit::FirstAidKitCardAction::exec(GameState& gs) {
    Player* saved = gs.GetPlayerUsingPlayerId(this->saved_);
    saved->GetCharacter()->SetWounds(saved->GetCharacter()->GetWounds() - 1);
}

std::unique_ptr<GenericAction> FirstAidKit::GetAction(int player, int saved)  {
    return std::make_unique<FirstAidKitCardAction>(this, player, saved);
}

Compass::CompassCardAction::CompassCardAction(Compass* owner)
    : owner_(owner) {}

void Compass::CompassCardAction::exec(GameState& gs) {
    Card* card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
}

std::unique_ptr<GenericAction> Compass::GetAction()  {
    return std::make_unique<CompassCardAction>(this);
}

Bait::BaitCardAction::BaitCardAction(Bait* owner)
    : owner_(owner) {};

void Bait::BaitCardAction::exec(GameState& gs) {
    std::size_t current_size = gs.GetSizeOfOutboard();
    for (std::size_t i = 0; i < current_size; i++) {
        Character* outboard_character = gs.GetCharacterOutboard(i);
        outboard_character->SetWounds(outboard_character->GetWounds() + 1);
    }
}

std::unique_ptr<GenericAction> Bait::GetAction()  {
    return std::make_unique<BaitCardAction>(this);
}

Lifeline::LifelineCardAction::LifelineCardAction(Lifeline* owner, int player, int saved)
    : owner_(owner), saved_(saved)
    {
        owner->SetPlayer(player);
    }

void Lifeline::LifelineCardAction::exec(GameState& gs) {
    Player* saved = gs.GetPlayerUsingPlayerId(this->saved_);
    saved->GetCharacter()->SetWounds(saved->GetCharacter()->GetWounds() - 1);
}

std::unique_ptr<GenericAction> Lifeline::GetAction(int player, int saved)  {
    return std::make_unique<LifelineCardAction>(this, player, saved);
}