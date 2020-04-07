#pragma once

#include "item.h"
#include "weapon.h"
#include "character.h"
#include "game_state.h"

class Universal : public Item {

};

class Paddle : public Universal {
  public:
    void RowWithPaddle(GameState* current_game_state);
};

class FlareGun : public Universal {
  public:
    void AddThreeNavigation(GameState* current_game_state);
};