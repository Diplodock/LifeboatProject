#include "game_state.h"

#include <cassert>

 Navigation* GameState::GetNavigationCard() const {
    assert(not_used_navigation_cards_.size() > 0) {
    Navigation* current_navigation_card = not_used_navigation_cards_[0];
    not_used_navigation_cards_.pop_front();
    return current_navigation_card;
 }

 int GameState::GetSizeOfOutboard() const {
    return outboard_.size();
 }

Character* GameState::GetCharacterOutboard(std::size_t i) const {
    assert(0 <= i < not_used_navigation_cards_.size());
    return outboard_[i];

}

 void GameState::PutCardOnNavigationTable(Navigation* current_navigation) {
     navigation_table_.push_back(current_navigation);
 }