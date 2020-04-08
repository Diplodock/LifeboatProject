#include "universal.h"

void Paddle::RowWithPaddle(GameState* current_game_state) {
    Card* card = (*current_game_state).GetNavigationCard();
    int id = (*current_game_state).GetIdCard(card);
    (*current_game_state).AddToChoice(id);
}

void FlareGun::AddThreeNavigation(GameState* current_game_state) {
    for (std::size_t i = 0; i < 3; i++) {
        Card* card = (*current_game_state).GetNavigationCard();
        int id = (*current_game_state).GetIdCard(card);
        (*current_game_state).AddToChoice(id);
    }
}