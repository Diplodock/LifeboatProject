#include "Character.h"

#include <algorithm>

Character::Character(std::string name, std::string description, int strength, int survival_bonus)
    : strength_(strength), survival_bonus_(survival_bonus), health_(100)
{
    name_ = name;
    description_ = description;
}

int Character::GetHealth() const {
    return health_;
}

int Character::GetStrength() const {
    return strength_;
}

int Character::GetSurvivalBonus() const {
    return survival_bonus_;
}

bool Character::IfExhausted() const {
    return exhausted_;
}

bool Character::IfCriticalState() const {
    return critical_state_;
}

Item Character::GetItem(int i) const {
    return *backpack_[i];
}

void Character::SetHealth(int health) {
    health_ = health;
}

void Character::AddItem(Item item) {
    backpack_.push_back(std::make_unique<Weapon>());
}

// bool Character::Fight(Character target) { // TODO: add ally support and weapon
//     exhausted_ = true;
//     target.exhausted_ = true;
//     if (GetMaxWeaponPoints() + strength_ > target.GetMaxWeaponPoints() + target.strength_) {
//         target.health_ -= 100 / target.strength_;
//         return true;
//     } // is it allowed to use multiple weapons?
//     else {
//         health_ -= 100 / strength_;
//         return false;
//     }
// }

void Character::UpdateState() {
    if (health_ <= strength_ / 100) {
        critical_state_ = true;
    }
}
