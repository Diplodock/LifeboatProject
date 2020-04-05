#pragma once

#include "item.h"

class Weapon : public Item {
  public:
    Weapon(int damage_points);
    int GetDamagePoints();
    
  private:
    int damage_points_;
};