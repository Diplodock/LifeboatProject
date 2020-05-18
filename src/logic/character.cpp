#include "character.h"

#include <algorithm>

Character::Character()
{
    characterOptions_.health = 100;
    characterOptions_.exhausted = false;
    characterOptions_.critical_state = false;
    characterOptions_.alive = true;
    characterOptions_.hold_umbrella = false;
    characterOptions_.thirst = false;
    characterOptions_.wounds = 0;
}

int Character::GetHealth() const {
    return characterOptions_.health;
}

int Character::GetStrength() const {
    return characterOptions_.strength;
}

int Character::GetSurvivalBonus() const {
    return characterOptions_.survival_bonus;
}

int Character::GetWounds() const {
    return characterOptions_.wounds;
}

bool Character::IfExhausted() const {
    return characterOptions_.exhausted;
}

bool Character::IfCriticalState() const {
    return characterOptions_.critical_state;
}

bool Character::IfAlive() const {
    return characterOptions_.alive;
}

bool Character::IfThirsty() const {
    return characterOptions_.thirst;
}

bool Character::IfHoldsUmbrella() const {
    return characterOptions_.hold_umbrella;
};

ItemPtr Character::GetItem(int i) const {
    return backpack_[i];
}

void Character::SetHealth(int health) {
    characterOptions_.health = health;
}

void Character::SetWounds(int number_of_wounds) {
    characterOptions_.wounds = number_of_wounds;
}

void Character::SetThirst(bool if_thirsty) {
    characterOptions_.thirst = if_thirsty;
}

void Character::SetExhausted(bool if_exhausted) {
    characterOptions_.exhausted = if_exhausted;
}

void Character::AddItem(ItemPtr item) {
    backpack_.push_back(item);
}

void Character::HoldUmbrella(bool holds) {
    characterOptions_.hold_umbrella = holds;
};

void Character::UpdateState() {
    if (characterOptions_.health <= 100 / characterOptions_.strength) {
        characterOptions_.critical_state = true;
    }
    if (characterOptions_.thirst) {
        characterOptions_.wounds++;
        characterOptions_.health -= 100 / characterOptions_.strength;
    }
}
