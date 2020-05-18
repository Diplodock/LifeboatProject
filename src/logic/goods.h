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
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player)  override;
};


class Umbrella : public Goods {
  public:
    class UmbrellaCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player)  override;
};

class FirstAidKit : public Goods {
  public:
    class FirstAidKitCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};

class Compass : public Goods {
  public:
    class CompassCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction()  override;
};

class Bait : public Goods {
    public:
    class BaitCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction()  override;
};

class Lifeline : public Goods {
  public:
    class LifelineCardAction : public GenericAction {
      using GenericAction::GenericAction;
      public:
        void exec(GameState& gs) override;
    };
    //std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};