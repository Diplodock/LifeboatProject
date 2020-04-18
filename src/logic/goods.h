#pragma once

#include "item.h"
#include "weapon.h"
#include "character.h"
#include "game_state.h"
#include "action.h"

class GameState;

class Goods : public Item {
};

class Water : public Goods {
  public:
    class WaterCardAction : public GenericAction {
      public:
        WaterCardAction(Water* owner, int player);
        void exec(GameState& gs) override;
      private:
        Water* owner_;
    };
    std::unique_ptr<GenericAction> GetAction(int player)  override;
};


class Umbrella : public Goods {
  public:
    class UmbrellaCardAction : public GenericAction {
      public:
        UmbrellaCardAction(Umbrella* owner, int player);
        void exec(GameState& gs) override;
      private:
        Umbrella* owner_;
    };
    std::unique_ptr<GenericAction> GetAction(int player)  override;
};

class FirstAidKit : public Goods {
  public:
    class FirstAidKitCardAction : public GenericAction {
      public:
        FirstAidKitCardAction(FirstAidKit* owner, int player, int saved);
        void exec(GameState& gs) override;
      private:
        FirstAidKit* owner_;
        int saved_;
    };
    std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};

class Compass : public Goods {
  public:
    class CompassCardAction : public GenericAction {
      public:
        CompassCardAction(Compass* owner);
        void exec(GameState& gs) override;
      private:
        Compass* owner_;
    };
    std::unique_ptr<GenericAction> GetAction()  override;
};

class Bait : public Goods {
    public:
    class BaitCardAction : public GenericAction {
      public:
        BaitCardAction(Bait* owner);
        void exec(GameState& gs) override;
      private:
        Bait* owner_;
    };
    std::unique_ptr<GenericAction> GetAction()  override;
};

class Lifeline : public Goods {
  public:
    class LifelineCardAction : public GenericAction {
      public:
        LifelineCardAction(Lifeline* owner, int player, int saved);
        void exec(GameState& gs) override;
      private:
        Lifeline* owner_;
        int saved_;
    };
    std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};