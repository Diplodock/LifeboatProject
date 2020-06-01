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

using NavigationPtr = std::shared_ptr<Navigation>;
using CharacterPtr = std::shared_ptr<Character>;
using PlayerPtr = std::shared_ptr<Player>;
using CardPtr = std::shared_ptr<Card>;
using AddPtr = std::shared_ptr<Additional>;

class Board;

class GameState {
  public:
    GameState(std::size_t number_of_players);

    int GetChosenNav() const;
    int GetSizeUnusedNavigation() const;
    int GetSizeOfChoice() const;
    int GetNumberOfSeagulls() const;
    int GetNumberOfPlayers() const;
    Navigation GetChosenNavigationCard();
    NavigationPtr GetNavigationCard();
    ItemPtr GetItemCard();
    int GetIdCard(CardPtr card);
    CardPtr GetCard(int id);
    PlayerPtr GetPlayerUsingPlayerId(int id);
    int GetSizeOfOutboard() const;
    CharacterPtr GetCharacterOutboard(std::size_t i) const;
    void GetChosen(int id);
    int GetTurn();
    CharacterPtr GetFought(std::size_t index) const;
    CharacterPtr GetRowed(std::size_t index) const;
    std::size_t GetSizeOfFought() const;
    std::size_t GetSizeOfRowed() const;
    std::vector<std::string> GetAvailableActions();
    std::vector<std::string> GetAvailableActions(int id, int player);

    void SetNumberOfSeagulls(int number_of_seagulls);
    void AddCardFought(CharacterPtr current_character);
    void AddCardRowed(CharacterPtr current_character);
    void AddCardOutboard(CharacterPtr current_character);
    void AddNotUsedNavigation(NavigationPtr current_navigation);
    void AddTheRestNavigation();
    void AddNotUsedItem(ItemPtr current_item);
    void AddUsedNavigation(NavigationPtr current_navigation);
    void AddChosenNavigation(int id);
    void AddUsedItem(ItemPtr current_item);
    void AddToChoice(int to_choice);
    void AddPlayerCharacter(int player, int id);
    void AddCharacter(CharacterPtr character);
    void BoundCardWithId(int id, CardPtr card);
    void SetPlayer(PlayerPtr player);
    void SetLast(int player);
    void AddAvailableAction(std::string action, int round);
    void RemoveAvailableAction(std::string action, int round);

    void AddSListener(std::shared_ptr<SeagullsListener> l);
    void AddAddListener(std::shared_ptr<AddCardsOnBoardListener> l);
    void AddRemUsedListener(std::shared_ptr<RemoveUsedCardListener> l);
    void AddRemNotUsedListener(std::shared_ptr<RemoveNotUsedCardsListener> l);
    void AddHealthListener(std::shared_ptr<HealthListener> l);
    void AddUmbrellaListener(std::shared_ptr<UmbrellaListener> l);
    void AddOwnerListener(std::shared_ptr<OwnerListener> l);
    void AddEListener(std::shared_ptr<ExhaustedListener> l);
    void AddDListener(std::shared_ptr<DeathListener> l);
    void AddTListener(std::shared_ptr<ThirstListener> l);
    void AddOListener(std::shared_ptr<OutboardListener> l);
    void AddTuListener(std::shared_ptr<TurnListener> l);
    void AddRoundListener(std::shared_ptr<RoundListener> l);

    std::vector<int> current_choice_;

    void NotifyHealth(int id, int points);
    void NotifyExhausted(int id, bool is);
    void NotifyThirst(int id, bool is);
    void NotifyUmbrella(int id, bool is);
    void NotifyOwner(int id, int card);
    void NotifyUsed(int id);

    std::vector<int> GetBackpack(int id);

    void FinishRound();
    void UpdatePart();
  private:
    std::vector<std::vector<std::string>> available_actions_;

    int number_of_seagulls_ = 0;
    int number_of_players_ = 6;
    int last_player_ = 0;
    int chosen_navigation_card_;
    int turn_ = 0;
    int round_ = 0;
    std::vector<std::string> rounds_ = {
      "Take items", "Distribution of supplies", "Action time", "Choose navigation card"
    };
    std::unordered_map<CardPtr, int> get_id_using_card_;
    std::unordered_map<CharacterPtr, int> get_player_using_character_id_;
    std::unordered_map<int, CardPtr> get_card_using_id_;
    std::vector<CharacterPtr> get_character_id_using_player_;
    std::vector<PlayerPtr> get_player_;
    std::vector<CharacterPtr> fought_;
    std::vector<CharacterPtr> rowed_;
    std::vector<CharacterPtr> outboard_;
    std::vector<CharacterPtr> characters_;
    std::deque<NavigationPtr> not_used_navigation_cards_;
    std::deque<ItemPtr> not_used_items_;
    std::vector<NavigationPtr> used_navigation_cards_;
    std::vector<ItemPtr> used_items_;


    std::vector<std::shared_ptr<SeagullsListener>> sListeners;
    std::vector<std::shared_ptr<AddCardsOnBoardListener>> addListeners;
    std::vector<std::shared_ptr<RemoveUsedCardListener>> remUsedListeners;
    std::vector<std::shared_ptr<RemoveNotUsedCardsListener>> remNotUsedListeners;
    std::vector<std::shared_ptr<HealthListener>> hListeners;
    std::vector<std::shared_ptr<UmbrellaListener>> uListeners;
    std::vector<std::shared_ptr<OwnerListener>> ownListeners;
    std::vector<std::shared_ptr<ExhaustedListener>> eListeners;
    std::vector<std::shared_ptr<DeathListener>> dListeners;
    std::vector<std::shared_ptr<ThirstListener>> tListeners;
    std::vector<std::shared_ptr<OutboardListener>> oListeners;
    std::vector<std::shared_ptr<TurnListener>> tuListeners;
    std::vector<std::shared_ptr<RoundListener>> roundListeners;
};
