#pragma once

#include <vector>
#include <memory>

#include "all_characters.h"

using CharacterPtr = std::shared_ptr<Character>;

class Player {
  public:
    CharacterPtr GetCharacter() const;

    void SetCharacter(CharacterPtr character);

  private:
    CharacterPtr character_;
    CharacterPtr friend_;
    CharacterPtr enemy_;
};