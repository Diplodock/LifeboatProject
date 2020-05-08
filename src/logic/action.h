#pragma once

class GameState;

class GenericAction {
  public:
    GenericAction(int player, int id, int other_card);
    virtual void exec(GameState& gs) = 0;
  protected:
    int player_ = 0;
    int id_ = 0;
    int other_card_ = 0;
};

class TakeItemsAction : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class TakeNavigationCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class ChooseCharacterCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class ChooseItem : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class ChooseNavigationCard : public GenericAction {
  using GenericAction::GenericAction;
  public:
    void exec(GameState& gs) override;
};

class Row : public GenericAction {
  using GenericAction::GenericAction;
  public:
    Row(int player);
    void exec(GameState& gs) override;
};

class Fight : public GenericAction {
  using GenericAction::GenericAction;
  public:
    Fight(int player, int id);
    void exec(GameState& gs) override;
};

class TryToSwap : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TryToSwap(int player, int id);
    void exec(GameState& gs) override;
};

class TryToTakeGoods : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TryToTakeGoods(int player, int id_thing, int id_character);
    void exec(GameState& gs) override;
};

class TryToGiveGoods : public GenericAction {
  using GenericAction::GenericAction;
  public:
    TryToGiveGoods(int player, int id_thing, int id_character);
    void exec(GameState& gs) override;
};
