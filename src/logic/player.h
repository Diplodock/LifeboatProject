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

static Player player1;
static Player player2;
static Player player3;
static Player player4;
static Player player5;
static Player player6;
static Player player7;
static Player player8;