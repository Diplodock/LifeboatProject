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

static Water water1;
static Water water2;
static Water water3;
static Water water4;
static Water water5;
static Water water6;
static Water water7;
static Water water8;
static Water water9;
static Water water10;
static Water water11;
static Water water12;
static Water water13;
static Water water14;
static Water water15;
static Water water16;
static Water water17;

static Umbrella umbrella;

static Bait bait1;
static Bait bait2;

static FirstAidKit firstAidKit1;
static FirstAidKit firstAidKit2;
static FirstAidKit firstAidKit3;

static Lifeline lifeline;

static Compass compass;