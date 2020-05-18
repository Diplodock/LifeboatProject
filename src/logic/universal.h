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
    class PaddleCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player) override;
};

class FlareGun : public Universal {
  public:
    class FlareGunCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player) override;
};
