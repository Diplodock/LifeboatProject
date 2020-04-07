#include "game_state.h"

#include <cassert>

 Navigation* GameState::GetNavigationCard() {
    assert(not_used_navigation_cards_.size() > 0);
    not_used_navigation_cards_.pop_front();
    return not_used_navigation_cards_[0];
 }

 int GameState::GetSizeOfOutboard() const {
    return outboard_.size();
 }

Character* GameState::GetCharacterOutboard(std::size_t i) const {
    assert(0 <= i < not_used_navigation_cards_.size());
    return outboard_[i];
}

void GameState::GetChosen(int id) {
    std::size_t index = 0;
    while (current_choice_[index] != id) {
        index++;
    }
    for (std::size_t i = index; i < current_choice_.size() - 1; i++) {
        current_choice_[i] = current_choice_[i + 1];
    }
    current_choice_.pop_back();
}

 void GameState::PutCardOnNavigationTable(Navigation* current_navigation) {
    navigation_table_.push_back(current_navigation);
 }

void GameState::AddCardFought(Character* current_character) {
    fought_.push_back(current_character);
}

void GameState::AddCardRowed(Character* current_character) {
    rowed_.push_back(current_character);
}

void GameState::AddCardOutboard(Character* current_character) {
    outboard_.push_back(current_character);
}

void GameState::AddNotUsedNavigation(Navigation* current_navigation) {
    not_used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddNotUsedItem(Item* current_item) {
    not_used_items_.push_back(current_item);
}

void GameState::AddUsedNavigation(Navigation* current_navigation) {
    used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddUsedItem(Item* current_item) {
    used_items_.push_back(current_item);
}

void GameState::AddToChoice(int to_choice) {
    current_choice_.push_back(to_choice);
}

void GameState::AddCharacter(int id) {
    Character *current_character = dynamic_cast<Character*> (get_card_using_id[id]); 
    get_character_id_using_player.push_back(current_character);
    get_player_using_character_id[current_character] = id;
}