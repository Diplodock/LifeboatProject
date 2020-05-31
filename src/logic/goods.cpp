#include "goods.h"

void WaterCardAction::exec(GameState& gs) {
    PlayerPtr player = gs.GetPlayerUsingPlayerId(player_);
    player->GetCharacter()->SetThirst(false, gs);
    CharacterPtr charac = std::dynamic_pointer_cast<Character>(gs.GetCard(gs.GetCard(id_)->GetOwner()));
    charac->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> Water::GetAction(int player) {
//     return std::make_unique<WaterCardAction>(this, player);
// }

void UmbrellaCardAction::exec(GameState& gs) {
    PlayerPtr player = gs.GetPlayerUsingPlayerId(player_);
    player->GetCharacter()->HoldUmbrella(true, gs);
    CharacterPtr charac = std::dynamic_pointer_cast<Character>(gs.GetCard(gs.GetCard(id_)->GetOwner()));
    charac->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> Umbrella::GetAction(int player)  {
//     return std::make_unique<UmbrellaCardAction>(this, player);
// }

void FirstAidCardAction::exec(GameState& gs) {
    PlayerPtr player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr saved = player->GetCharacter();
    saved->SetHealth(saved->GetHealth() + 100 / saved->GetStrength(), gs);
    saved->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> FirstAidKit::GetAction(int player, int saved)  {
//     return std::make_unique<FirstAidKitCardAction>(this, player, saved);
// }

void CompassCardAction::exec(GameState& gs) {
    CardPtr card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
    CharacterPtr charac = std::dynamic_pointer_cast<Character>(gs.GetCard(gs.GetCard(id_)->GetOwner()));
    charac->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> Compass::GetAction()  {
//     return std::make_unique<CompassCardAction>(this);
// }

void BaitCardAction::exec(GameState& gs) {
    std::size_t current_size = gs.GetSizeOfOutboard();
    for (std::size_t i = 0; i < current_size; i++) {
        CharacterPtr outboard_character = gs.GetCharacterOutboard(i);
        outboard_character->SetHealth(outboard_character->GetHealth() - 100 / outboard_character->GetStrength(), gs);
    }
    CharacterPtr charac = std::dynamic_pointer_cast<Character>(gs.GetCard(gs.GetCard(id_)->GetOwner()));
    charac->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> Bait::GetAction()  {
//     return std::make_unique<BaitCardAction>(this);
// }

void LifelineCardAction::exec(GameState& gs) {
    PlayerPtr player = gs.GetPlayerUsingPlayerId(player_);
    CharacterPtr saved = player->GetCharacter();
    saved->SetHealth(saved->GetHealth() + 100 / saved->GetStrength(), gs);
    saved->RemoveItem(std::dynamic_pointer_cast<Item>(gs.GetCard(id_)), gs);
}

// std::unique_ptr<GenericAction> Lifeline::GetAction(int player, int saved)  {
//     return std::make_unique<LifelineCardAction>(this, player, saved);
// }

ItemPtr create(Item obj) {
    return std::make_shared<Item>(obj);
}

static Water water1;
static Water water2;
static Water water3;
static Water water4;
static Water water5;
static Water water6;
static Water water7;
static Water water8;
static Water water9;
static Water water10;
static Water water11;
static Water water12;
static Water water13;
static Water water14;
static Water water15;
static Water water16;
static Water water17;

static Umbrella umbrella;

static Bait bait1;
static Bait bait2;

static FirstAidKit firstAidKit1;
static FirstAidKit firstAidKit2;
static FirstAidKit firstAidKit3;

static Lifeline lifeline;

static Compass compass;

std::vector<ItemPtr> listGoods = 
    {create(water1), create(water2), create(water3), create(water4), 
    create(water5), create(water6), create(water7), create(water8), 
    create(water9), create(water10), create(water11), create(water12), 
    create(water13), create(water14), create(water15), create(water16), 
    create(water17), create(umbrella), create(bait1), create(bait2),
    create(firstAidKit1), create(firstAidKit2), create(firstAidKit3),
    create(lifeline), create(compass)};