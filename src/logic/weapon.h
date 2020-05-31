#pragma once

#include "item.h"

class Weapon : public Item {
  public:
    Weapon() { specific_action_ = ""; }
};