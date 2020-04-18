#include "game_state.h"

#include <cassert>

#include "goods.h"
#include "universal.h"

int GameState::GetNumberOfSeagulls() const {
    return number_of_seagulls_;
}

Navigation* GameState::GetNavigationCard() {
    assert(not_used_navigation_cards_.size() > 0);
    Navigation* current_card_ = not_used_navigation_cards_[0];
    not_used_navigation_cards_.pop_front();
    return current_card_;
 }

Item* GameState::GetItemCard() {
    assert(not_used_items_.size() > 0);
    Item* current_card_ = not_used_items_[0];
    not_used_items_.pop_front();
    return current_card_;
}

int GameState::GetIdCard(Card* card) {
    return get_id_using_card_[card];
}

Card* GameState::GetCard(int id) {
    return get_card_using_id_[id];
}

Player* GameState::GetPlayerUsingPlayerId(int id) {
    return get_player_[id];
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

Character* GameState::GetFought(std::size_t index) const {
    return fought_[index];
}

Character* GameState::GetRowed(std::size_t index) const {
    return rowed_[index];
}

std::size_t GameState::GetSizeOfFought() const {
    return fought_.size();
}

std::size_t GameState::GetSizeOfRowed() const {
    return rowed_.size();
}

void GameState::SetNumberOfSeagulls(int number_of_seagulls) {
    number_of_seagulls_ = number_of_seagulls;
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

void GameState::AddTheRestNavigation() {
    for (std::size_t i = 0; i < current_choice_.size(); i++) {
        Navigation* current_navigation = dynamic_cast<Navigation*> (get_card_using_id_[current_choice_[i]]);
        not_used_navigation_cards_.push_back(current_navigation);
    }
}

void GameState::AddNotUsedItem(Item* current_item) {
    not_used_items_.push_back(current_item);
}

void GameState::AddUsedNavigation(Navigation* current_navigation) {
    used_navigation_cards_.push_back(current_navigation);
}

void GameState::AddChosenNavigation(int id) {
    Navigation* current_navigation = dynamic_cast<Navigation*> (get_card_using_id_[id]);
    chosen_navigation_card_ = current_navigation;
}

void GameState::AddUsedItem(Item* current_item) {
    used_items_.push_back(current_item);
}

void GameState::AddToChoice(int to_choice) {
    current_choice_.push_back(to_choice);
}

void GameState::AddPlayerCharacter(int player, int id) {
    Character* current_character = dynamic_cast<Character*> (get_card_using_id_[id]); 
    get_character_id_using_player_.push_back(current_character);
    get_player_using_character_id_[current_character] = player;
}

void GameState::AddCharacter(Character* character) {
    characters_.push_back(character);
}

void GameState::BoundCardWithId(int id, Card* card) {
    get_id_using_card_[card] = id;
    get_card_using_id_.push_back(card);
}

void GameState::SetPlayer(Player* player) {
    get_player_.push_back(player);
}

void GameState::FinishRound() {
    fought_.clear();
    rowed_.clear();
    outboard_.clear();
    current_choice_.clear();
}