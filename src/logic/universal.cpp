#include "universal.h"

void Paddle::RowWithPaddle(GameState* current_game_state) {
    Navigation* current_navigation_card = (*current_game_state).GetNavigationCard();
    (*current_game_state).PutCardOnNavigationTable(current_navigation_card);
}

void FlareGun::AddThreeNavigation(GameState* current_game_state) {
    for (std::size_t i = 0; i < 3; i++) {
        Navigation* current_navigation_card = (*current_game_state).GetNavigationCard();
        (*current_game_state).PutCardOnNavigationTable(current_navigation_card);
    }
}