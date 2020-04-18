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
      public:
        PaddleCardAction(Paddle* owner, int player);
        void exec(GameState& gs) override;
      private:
        Paddle* owner_;
    };
    std::unique_ptr<GenericAction> GetAction(int player) override;
};

class FlareGun : public Universal {
  public:
    class FlareGunCardAction : public GenericAction {
      public:
        FlareGunCardAction(FlareGun* owner, int player);
        void exec(GameState& gs) override;
      private:
        FlareGun* owner_;
    };
    std::unique_ptr<GenericAction> GetAction(int player) override;
};