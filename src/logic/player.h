#pragma once

#include <vector>

#include "all_characters.h"

class Player {
  public:
    Character* GetCharacter() const;

    void SetCharacter(Character* character);

  private:
    Character* character_;
    Character* friend_;
    Character* enemy_;
};