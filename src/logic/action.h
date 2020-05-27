#pragma once

#include <string>

class GameState;

class GenericAction {
  public:
    GenericAction(int player, int id, int other_card);
    virtual void exec(GameState& gs) {};

    int GetPlayer();
    int GetId();
  protected:
    int player_ = 0;
    int id_ = 0;
    int other_card_ = 0;
    std::string name_ = "";
    std::string description_ = "";
};

class TakeItemsAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TakeItemsAction();
    void exec(GameState& gs) override;
};

class Example : public GenericAction {
  using GenericAction::GenericAction;
  public:
    Example();
    void exec(GameState& gs) override;

};

class TakeNavigationCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TakeNavigationCard();
    void exec(GameState& gs) override;
};

class ChooseCharacterCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    ChooseCharacterCard();
    void exec(GameState& gs) override;
};

class ChooseItem : public GenericAction {
  using GenericAction::GenericAction;
  public:
    ChooseItem();
    void exec(GameState& gs) override;
};

class ChooseNavigationCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    ChooseNavigationCard();
    void exec(GameState& gs) override;
};

class Row : public GenericAction {
  using GenericAction::GenericAction;
  public:
    Row();
    void exec(GameState& gs) override;
};

class Fight : public GenericAction {
  using GenericAction::GenericAction;
  public:
    Fight();
    void exec(GameState& gs) override;
};

class TryToSwap : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class TryToTakeGoods : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TryToTakeGoods();
    void exec(GameState& gs) override;
};

class TryToGiveGoods : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TryToGiveGoods();
    void exec(GameState& gs) override;
};
