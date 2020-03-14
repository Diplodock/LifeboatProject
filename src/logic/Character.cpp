#include "Character.h"

#include <algorithm>

Character::Character()
{
    characterOptions_.health = 100;
    characterOptions_.exhausted = false;
    characterOptions_.critical_state = false;
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

bool Character::IfExhausted() const {
    return characterOptions_.exhausted;
}

bool Character::IfCriticalState() const {
    return characterOptions_.critical_state;
}

Item Character::GetItem(int i) const {
    return *backpack_[i];
}

void Character::SetHealth(int health) {
    characterOptions_.health = health;
}

void Character::AddItem(Item* item) {
    backpack_.push_back(item);
}

int Character::GetMaxWeaponPoints() {
    int max_points = 0;
    for (int i = 0; i < backpack_.size(); i++) {
        Weapon *current_weapon = dynamic_cast<Weapon*> (backpack_[i]); 
        if (current_weapon != nullptr) {
            if (max_points < (*current_weapon).GetDamagePoints()) {
                max_points = (*current_weapon).GetDamagePoints();
            };
        }
    }
    return max_points;
}


bool Character::Fight(Character target) { // TODO: add ally support and weapon
    characterOptions_.exhausted = true;
    target.characterOptions_.exhausted = true;
    if (GetMaxWeaponPoints() + characterOptions_.strength > target.GetMaxWeaponPoints() + target.characterOptions_.strength) {
        target.characterOptions_.health -= 100 / target.characterOptions_.strength;
        return true;
    } // is it allowed to use multiple weapons?
    else {
        characterOptions_.health -= 100 / characterOptions_.strength;
        return false;
    }
}

void Character::UpdateState() {
    if (characterOptions_.health <= characterOptions_.strength / 100) {
        characterOptions_.critical_state = true;
    }
}
