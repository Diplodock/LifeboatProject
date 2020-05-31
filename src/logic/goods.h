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
    Water() { specific_action_ = "WaterCardAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player)  override;
};

class WaterCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class Umbrella : public Goods {
  public:
    Umbrella() { specific_action_ = "UmbrellaCardAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player)  override;
};

class UmbrellaCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class FirstAidKit : public Goods {
  public:
    FirstAidKit() { specific_action_ = "FirstAidCardAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};

class FirstAidCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class Compass : public Goods {
  public:
    Compass() { specific_action_ = "CompassCardAction"; }
    //std::unique_ptr<GenericAction> GetAction()  override;
};

class CompassCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class Bait : public Goods {
  public:
    Bait() { specific_action_ = "BaitCardAction"; }
    //std::unique_ptr<GenericAction> GetAction()  override;
};

class BaitCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class Lifeline : public Goods {
  public:
    Lifeline() { specific_action_ = "LifelineCardAction"; }
    //std::unique_ptr<GenericAction> GetAction(int player, int saved)  override;
};

class LifelineCardAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};