#pragma once

#include <vector>
#include <deque>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <random>

#include "all_cards.h"
#include "all_characters.h"
#include "additional.h"
#include "navigation.h"
#include "weapon.h"
#include "player.h"
#include "listener.h"

//#include <json.hpp>

//using json = nlohmann::json;

class GameState {
  public:
    GameState(std::size_t number_of_players);

    int GetChosenNav() const;
    int GetSizeUnusedNavigation() const;
    int GetSizeOfChoice() const;
    int GetNumberOfSeagulls() const;
    int GetNumberOfPlayers() const;
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
    std::vector<std::string> GetAvailableActions(int player, int id);
    bool IsActionAvailable(int player, int id, std::string action);
    
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
    void SetPlayer(Player* player);
    void SetLast(int player);
    void AddAvailableAction(int id, std::string action, int player = 10);
    void RemoveAvailableAction(int id, std::string action, int player = 10);

    void FinishRound();

  private:
    std::vector<std::vector<std::vector<std::string>>> available_actions_;
    std::vector<std::vector<std::unordered_map<std::string, bool>>> is_action_;

    int number_of_seagulls_ = 0;
    int number_of_players_ = 4;
    int last_player_ = 0;
    int chosen_navigation_card_;
    int turn_ = 0;
    std::unordered_map<Card*, int> get_id_using_card_;
    std::unordered_map<Character*, int> get_player_using_character_id_;
    std::unordered_map<int, Card*> get_card_using_id_;
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

    std::vector<SeagullsListener*> sListeners;
    std::vector<AddCardsOnBoardListener*> addListeners;
    std::vector<RemoveUsedCardListener*> remUsedListeners;
    std::vector<RemoveNotUsedCardsListener*> remNotUsedListeners;
    std::vector<ExhaustedListener*> eListeners;
    std::vector<DeathListener*> dListeners;
    std::vector<ThirstListener*> tListeners;
    std::vector<OutboardListener*> oListeners;
    std::vector<TurnListener*> tuListeners;
};
