#include "universal.h"

void PaddleCardAction::exec(GameState& gs) {
    CardPtr card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
}

// std::unique_ptr<GenericAction> Paddle::GetAction(int player)  {
//     return std::make_unique<PaddleCardAction>(this, player);
// }

void FlareGunCardAction::exec(GameState& gs) {
    for (std::size_t i = 0; i < 3; i++) {
        CardPtr card = gs.GetNavigationCard();
        int id = gs.GetIdCard(card);
        gs.AddToChoice(id);
    }
    gs.GetCard(id_)->RemoveAvailableAction("FlareGunCardAction");
    //gs.AddUsedItem(std::GetCard(id_));
}

// std::unique_ptr<GenericAction> FlareGun::GetAction(int player)  {
//     return std::make_unique<FlareGunCardAction>(this, player);
// }

ItemPtr createUni(Item obj) {
    return std::make_shared<Item>(obj);
}

static Paddle paddle1;
static Paddle paddle2;

static FlareGun flareGun;

std::vector<ItemPtr> listUni = {createUni(paddle1), createUni(paddle2), createUni(flareGun)};
