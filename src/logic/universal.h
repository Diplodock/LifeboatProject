#pragma once

#include "item.h"
#include "weapon.h"
#include "character.h"
#include "game_state.h"
#include "action.h"

class Universal : public Item {

};

class Paddle : public Universal {
  public:
    Paddle() { specific_action_ = "PaddleCardAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player) override;
};

class PaddleCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class FlareGun : public Universal {
  public:
    FlareGun() { specific_action_ = "FlareGunAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player) override;
};

class FlareGunCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};
