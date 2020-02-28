#ifndef LIFEBOAT_LOGIC_CHARACTER_H_
#define LIFEBOAT_LOGIC_CHARACTER_H_

#include <vector>
#include <memory>

#include "Card.h"
#include "Item.h"
#include "Weapon.h"

class Character : public Card {
  public:
    Character(std::string name, std::string description, int strength, int survival_bonus);
    int GetHealth() const;
    int GetStrength() const;
    int GetSurvivalBonus() const;
    bool IfExhausted() const;
    bool IfCriticalState() const;
    Item GetItem(int item) const;
    void SetHealth(int health);
    void AddItem(Item item);
    bool Fight(Character target);
    void UpdateState();
  protected:
    int health_;
    int strength_;
    int survival_bonus_;
    bool exhausted_;
    bool critical_state_;
    std::vector<std::unique_ptr<Item>> backpack_;
};

#endif // LIFEBOAT_LOGIC_CHARACTER_H_