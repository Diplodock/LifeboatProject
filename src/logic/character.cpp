#include "character.h"

#include <algorithm>

Character::Character()
{
    characterOptions_.health = 100;
    characterOptions_.exhausted = false;
    characterOptions_.critical_state = false;
    characterOptions_.alive = true;
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

Item Character::GetItem(int i) const {
    return *backpack_[i];
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

void Character::AddItem(Item* item) {
    backpack_.push_back(item);
}

void Character::HoldUmbrella(bool holds) {
    characterOptions_.hold_umbrella = holds;
};

// int Character::GetMaxWeaponPoints() {
//     int max_points = 0;
//     for (int i = 0; i < backpack_.size(); i++) {
//         Weapon *current_weapon = dynamic_cast<Weapon*> (backpack_[i]); 
//         if (current_weapon != nullptr) {
//             if (max_points < (*current_weapon).GetDamagePoints()) {
//                 max_points = (*current_weapon).GetDamagePoints();
//             };
//         }
//     }
//     return max_points;
// }


bool Character::Fight(Character* target) { // TODO: add ally support and weapon
    characterOptions_.exhausted = true;
    (*target).characterOptions_.exhausted = true;
    if (characterOptions_.strength > (*target).characterOptions_.strength) {
        (*target).characterOptions_.health -= 100 / (*target).characterOptions_.strength;
        return true;
    }
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
