#pragma once

#include <vector>
#include <memory>

#include "card.h"
#include "item.h"
#include "weapon.h"

class Item;

using ItemPtr = std::shared_ptr<Item>;

struct CharacterOptions {
    int health;
    int strength;
    int survival_bonus;
    int wounds;
    bool exhausted;
    bool critical_state;
    bool alive;
    bool thirst;
    bool hold_umbrella;
};

class Character : public Card {
  public:
    Character();
    int GetHealth() const;
    int GetStrength() const;
    int GetSurvivalBonus() const;
    int GetWounds() const;
    bool IfExhausted() const;
    bool IfCriticalState() const;
    bool IfAlive() const;
    bool IfThirsty() const;
    bool IfHoldsUmbrella() const;

    ItemPtr GetItem(int item) const;
    void SetHealth(int health);
    void SetWounds(int number_of_wounds);
    void SetThirst(bool is_thirsty);
    void SetExhausted(bool is_exhausted);
    void AddItem(ItemPtr item);
    void HoldUmbrella(bool holds);
    
    void UpdateState();

  protected:
    CharacterOptions characterOptions_;
    std::vector<ItemPtr> backpack_;
};