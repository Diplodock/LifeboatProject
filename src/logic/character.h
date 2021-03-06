#pragma once

#include <vector>
#include <memory>

#include "card.h"
#include "item.h"
#include "weapon.h"

class Item;
class GameState;

using ItemPtr = std::shared_ptr<Item>;

struct CharacterOptions {
    int health = 0;
    int strength;
    int survival_bonus;
    int wounds;
    bool exhausted = false;
    bool critical_state = false;
    bool alive = true;
    bool thirst = false;
    bool hold_umbrella = false;
};

class Character : public Card {
  public:
    Character();
    int GetHealth() const;
    int GetStrength() const;
    int GetSurvivalBonus() const;
    int GetWounds() const;
    std::vector<ItemPtr> GetCharBackpack() const;
    bool IfExhausted() const;
    bool IfCriticalState() const;
    bool IfAlive() const;
    bool IfThirsty() const;
    bool IfHoldsUmbrella() const;

    ItemPtr GetItem(int item) const;
    void SetHealth(int health, GameState &gs);
    void SetWounds(int number_of_wounds);
    void SetThirst(bool is_thirsty, GameState &gs);
    void SetExhausted(bool is_exhausted, GameState &gs);
    void AddItem(ItemPtr item, GameState &gs);
    void RemoveItem(ItemPtr item, GameState &gs);
    void HoldUmbrella(bool holds, GameState &gs);
    
    void UpdateState(GameState &gs);

  protected:
    CharacterOptions characterOptions_;
    std::vector<ItemPtr> backpack_;
};