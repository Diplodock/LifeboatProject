#ifndef LIFEBOAT_LOGIC_CHARACTER_H_
#define LIFEBOAT_LOGIC_CHARACTER_H_

#include <vector>
#include <memory>

#include "Card.h"
#include "Item.h"
#include "Weapon.h"

struct CharacterOptions {
    int health;
    int strength;
    int survival_bonus;
    bool exhausted;
    bool critical_state;
};

class Character : public Card {
  public:
    Character();
    int GetHealth() const;
    int GetStrength() const;
    int GetSurvivalBonus() const;
    bool IfExhausted() const;
    bool IfCriticalState() const;

    Item GetItem(int item) const;
    void SetHealth(int health);
    void AddItem(Item* item);

    int GetMaxWeaponPoints();
    bool Fight(Character target);
    void UpdateState();

  protected:
    CharacterOptions characterOptions_;
    std::vector<Item*> backpack_;
};

#endif // LIFEBOAT_LOGIC_CHARACTER_H_