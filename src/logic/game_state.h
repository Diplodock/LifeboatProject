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
    int GetNumberOfSeagulls() const;
    Navigation* GetChosenNavigationCard();
    Navigation* GetNavigationCard();
    Item* GetItemCard();
    int GetIdCard(Card* card);
    Card* GetCard(int id);
    Player* GetPlayerUsingPlayerId(int id);
    int GetSizeOfOutboard() const;
    Character* GetCharacterOutboard(std::size_t i) const;
    void GetChosen(int id);
    Character* GetFought(std::size_t index) const;
    Character* GetRowed(std::size_t index) const;
    std::size_t GetSizeOfFought() const;
    std::size_t GetSizeOfRowed() const;
    
    void SetNumberOfSeagulls(int number_of_seagulls);
    void AddCardFought(Character* current_character);
    void AddCardRowed(Character* current_character);
    void AddCardOutboard(Character* current_character);
    void AddNotUsedNavigation(Navigation* current_navigation);
    void AddTheRestNavigation();
    void AddNotUsedItem(Item* current_item);
    void AddUsedNavigation(Navigation* current_navigation);
    void AddChosenNavigation(int id);
    void AddUsedItem(Item* current_item);
    void AddToChoice(int to_choice);
    void AddPlayerCharacter(int player, int id);
    void AddCharacter(Character* character);
    void BoundCardWithId(int id, Card* card);

    void FinishRound();

  private:
    int number_of_seagulls_ = 0;
    Navigation* chosen_navigation_card_;
    int turn_ = 0;
    std::unordered_map<Card*, int> get_id_using_card_;
    std::unordered_map<Character*, int> get_player_using_character_id_;
    std::vector<Card*> get_card_using_id_;
    std::vector<Character*> get_character_id_using_player_;
    std::vector<Player*> get_player_;
    std::vector<Character*> fought_;
    std::vector<Character*> rowed_;
    std::vector<Character*> outboard_;
    std::vector<Character*> characters_;
    std::deque<Navigation*> not_used_navigation_cards_;
    std::deque<Item*> not_used_items_;
    std::vector<Navigation*> used_navigation_cards_;
    std::vector<Item*> used_items_;
    std::vector<int> current_choice_;
};