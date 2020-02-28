#include "Weapon.h"

Weapon::Weapon(int damage_points)
    : damage_points_(damage_points)
{}

int Weapon::GetDamagePoints() {
    return damage_points_;
}