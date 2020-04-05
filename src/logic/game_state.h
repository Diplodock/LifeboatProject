#pragma once

#include <vector>
#include <deque>
#include <memory>

#include "all_characters.h"
#include "goods.h"
#include "additional.h"
#include "navigation.h"
#include "weapon.h"
#include "player.h"

class GameState {
  public:
    std::unique_ptr<Navigation> GetNavigationCard() const;
    int GetSizeOfOutboard() const;
    std::unique_ptr<Character> GetCharacterOutboard(std::size_t i) const;
    
    void PutCardOnNavigationTable(std::unique_ptr<Navigation> current_navigation);

  private:
    int number_of_seagulls_;
    std::unique_ptr<Navigation> chosen_navigation_card_;
    std::unique_ptr<Player> turn_;
    std::vector<std::unique_ptr<Character>> fought_;
    std::vector<std::unique_ptr<Character>> rowed_;
    std::vector<std::unique_ptr<Character>> outboard_;
    std::vector<std::unique_ptr<Character>> characters_;
    std::vector<std::unique_ptr<Navigation>> navigation_table_;
    std::deque<std::unique_ptr<Navigation>> not_used_navigation_cards_;
    std::deque<std::unique_ptr<Item>> not_used_items_;
    std::vector<std::unique_ptr<Navigation>> used_navigation_cards_;
    std::vector<std::unique_ptr<Item>> used_items_;
    std::vector<std::unique_ptr<Item>> opened_items_;
    std::vector<std::unique_ptr<Item>> hidden_items_;
};