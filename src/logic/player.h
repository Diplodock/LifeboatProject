#pragma once

#include <vector>

#include "all_characters.h"
#include "goods.h"
#include "additional.h"
#include "navigation.h"
#include "weapon.h"

class Player {
  public:

  private:
    Character* character_;
    Character* friend_;
    Character* enemy_;
};