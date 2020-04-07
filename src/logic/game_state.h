#pragma once

#include <vector>
#include <deque>
#include <memory>
#include <unordered_map>

#include "all_characters.h"
#include "goods.h"
#include "additional.h"
#include "navigation.h"
#include "weapon.h"
#include "player.h"

class GameState {
  public:
    Navigation* GetNavigationCard();
    int GetSizeOfOutboard() const;
    Character* GetCharacterOutboard(std::size_t i) const;
    void GetChosen(int id);
    
    void PutCardOnNavigationTable(Navigation* current_navigation);
    void AddCardFought(Character* current_character);
    void AddCardRowed(Character* current_character);
    void AddCardOutboard(Character* current_character);
    void AddNotUsedNavigation(Navigation* current_navigation);
    void AddNotUsedItem(Item* current_item);
    void AddUsedNavigation(Navigation* current_navigation);
    void AddUsedItem(Item* current_item);
    void AddToChoice(int to_choice);
    void AddCharacter(int id);


  private:
    int number_of_seagulls_;
    Navigation* chosen_navigation_card_;
    Player* turn_;
    std::unordered_map<Card*, int> get_id_using_card_;
    std::unordered_map<Character*, int> get_player_using_character_id;
    std::vector<Card*> get_card_using_id;
    std::vector<Character*> get_character_id_using_player;
    std::vector<Character*> fought_;
    std::vector<Character*> rowed_;
    std::vector<Character*> outboard_;
    std::vector<Character*> characters_;
    std::vector<Navigation*> navigation_table_;
    std::deque<Navigation*> not_used_navigation_cards_;
    std::deque<Item*> not_used_items_;
    std::vector<Navigation*> used_navigation_cards_;
    std::vector<Item*> used_items_;
    std::vector<Item*> opened_items_;
    std::vector<Item*> hidden_items_;
    std::vector<int> current_choice_;
};