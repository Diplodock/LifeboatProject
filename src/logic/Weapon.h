#ifndef LIFEBOAT_LOGIC_WEAPON_H_
#define LIFEBOAT_LOGIC_WEAPON_H_

#include "Item.h"

class Weapon : public Item {
  public:
    Weapon(int damage_points);
    int GetDamagePoints();
  private:
    int damage_points_;
};

#endif //LIFEBOAT_LOGIC_WEAPON_H_