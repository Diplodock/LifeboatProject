#pragma once

#include <vector>

class Board;

class Listener {
  public:
    virtual void notify() {};
};

class SeagullsListener : public Listener {
  public:
    SeagullsListener(void (*func)(int numberOfSeagulls, Board* b));
    void notify(int numberOfSeagulls, Board *b) {
      callbackFunc(numberOfSeagulls, b);
    }
    private:
      void (*callbackFunc)(int numberOfSeagulls, Board *b);
};

class AddCardsOnBoardListener : public Listener {
  public:
    AddCardsOnBoardListener(void (*func)(int id));
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class RemoveUsedCardListener : public Listener {
  public:
    RemoveUsedCardListener(void (*func)(int id));
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class RemoveNotUsedCardsListener : public Listener {
  public:
    RemoveNotUsedCardsListener(void (*func)(std::vector<int> ids));
    void notify(std::vector<int> ids) {
      callbackFunc(ids);
    }
  private:
    void (*callbackFunc)(std::vector<int> ids);
};

class HealthListener : public Listener {
  public:
    HealthListener(void (*func)(int id, int healthPoints));
    void notify(int id, int healthPoints) {
      callbackFunc(id, healthPoints);
    }
  private:
    void (*callbackFunc)(int id, int healthPoints);
};

class ExhaustedListener : public Listener {
  public:
    ExhaustedListener(void (*func)(int id, bool is_exhausted));
    void notify(int id, bool is_exhausted) {
      callbackFunc(id, is_exhausted);
    }
  private:
    void (*callbackFunc)(int id, bool is_exhausted);
};

class DeathListener : public Listener {
  public:
    DeathListener(void (*func)(int id, bool is_dead));
    void notify(int id, bool is_dead) {
      callbackFunc(id, is_dead);
    }
  private:
    void (*callbackFunc)(int id, bool is_dead);
};

class ThirstListener : public Listener {
  public:
    ThirstListener(void (*func)(int id, bool is_thirsty));
    void notify(int id, bool is_thirsty) {
      callbackFunc(id, is_thirsty);
    }
  private:
    void (*callbackFunc)(int id, bool is_thirsty);
};

class OutboardListener : public Listener {
  public:
    OutboardListener(void (*func)(int id));
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class TurnListener : public Listener {
  public:
    TurnListener(void (*func)(int id));
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};