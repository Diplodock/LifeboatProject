#pragma once

class GameState;

class GenericAction {
  public:
    virtual void exec(GameState& gs) = 0;
  protected:
    int player_ = 0;
    int id_ = 0;
};

class TakeItemsAction : public GenericAction {
  public:
    void exec(GameState& gs) override;
};

class TakeNavigationCard : public GenericAction {
  public:
    void exec(GameState& gs) override;
};

class ChooseCharacterCard : public GenericAction {
  public:
    ChooseCharacterCard(int player, int id);
    void exec(GameState& gs) override;
};

class ChooseItem : public GenericAction {
  public:
    ChooseItem(int player, int id);
    void exec(GameState& gs) override;
};

class ChooseNavigationCard : public GenericAction {
  public:
    ChooseNavigationCard(int player, int id);
    void exec(GameState& gs) override;
};

class Row : public GenericAction {
  public:
    Row(int player);
    void exec(GameState& gs) override;
};

class Fight : public GenericAction {
  public:
    Fight(int player, int id);
    void exec(GameState& gs) override;
};

class TryToSwap : public GenericAction {
  public:
    TryToSwap(int player, int id);
    void exec(GameState& gs) override;
};

class TryToTakeGoods : public GenericAction {
  public:
    TryToTakeGoods(int player, int id_thing, int id_character);
    void exec(GameState& gs) override;
};

class TryToGiveGoods : public GenericAction {
  public:
    TryToGiveGoods(int player, int id_thing, int id_character);
    void exec(GameState& gs) override;
};
