#include "universal.h"

void Paddle::PaddleCardAction::exec(GameState& gs) {
    Card* card = gs.GetNavigationCard();
    int id = gs.GetIdCard(card);
    gs.AddToChoice(id);
}

// std::unique_ptr<GenericAction> Paddle::GetAction(int player)  {
//     return std::make_unique<PaddleCardAction>(this, player);
// }

void FlareGun::FlareGunCardAction::exec(GameState& gs) {
    for (std::size_t i = 0; i < 3; i++) {
        Card* card = gs.GetNavigationCard();
        int id = gs.GetIdCard(card);
        gs.AddToChoice(id);
    }
}

// std::unique_ptr<GenericAction> FlareGun::GetAction(int player)  {
//     return std::make_unique<FlareGunCardAction>(this, player);
// }