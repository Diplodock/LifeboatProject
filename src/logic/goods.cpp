#include "goods.h"

void Water::drinkWater(Character* thirsty) {
    (*thirsty).SetThirst = false;
}

void Umbrella::useUmbrella(Character* thirsty) {
    (*thirsty).HoldUmbrella = true;
}

void FirstAidKit::healCharacter(Character* healed) {
    (*healed).SetWounds = (*healed).GetWounds - 1;
}

void Compass::addNavigation(GameState* current_game_state) {
    Navigation* current_navigation_card = (*current_game_state).GetNavigationCard();
    (*current_game_state).PutCardOnNavigationTable(current_navigation_card);
}

void Bait::baitSharks(GameState* current_game_state) {
    std::size_t current_size = (*current_game_state).GetSizeOfOutboard();
    for (std::size_t i = 0; i < current_size; i++) {
        Character* outboard_character = (*current_game_state).GetCharacterOutboard(i);
        (*outboard_character).SetWounds = (*outboard_character).GetWounds + 1;
    }
}

void Paddle::row(GameState* current_game_state) {
    Navigation* current_navigation_card = (*current_game_state).GetNavigationCard();
    (*current_game_state).PutCardOnNavigationTable(current_navigation_card);
}

void Lifeline::useLifiline(Character* saved) {
    (*saved).SetWounds = (*saved).GetWounds - 1;
}

void FlareGun::addThreeNavigation(GameState* current_game_state) {
    for (std::size_t i = 0; i < 3; i++) {
        Navigation* current_navigation_card = (*current_game_state).GetNavigationCard();
        (*current_game_state).PutCardOnNavigationTable(current_navigation_card);
    }
}