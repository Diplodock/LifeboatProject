#pragma once

#include <vector>
#include <functional>
#include <string>

class Board;

class Listener {
  public:
    virtual void notify() {};
};

class SeagullsListener : public Listener {
  public:
    SeagullsListener(std::function<void()> func);
    void notify() {
      callbackFunc();
    }
    private:
      std::function<void()> callbackFunc;
};

class AddCardsOnBoardListener : public Listener {
  public:
    AddCardsOnBoardListener(std::function<void(int)> func);
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    std::function<void(int id)> callbackFunc;
};

class RemoveUsedCardListener : public Listener {
  public:
    RemoveUsedCardListener(std::function<void(int)> func);
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    std::function<void(int id)> callbackFunc;
};

class RemoveNotUsedCardsListener : public Listener {
  public:
    RemoveNotUsedCardsListener(std::function<void(std::vector<int> ids)> func);
    void notify(std::vector<int> ids) {
      callbackFunc(ids);
    }
  private:
    std::function<void(std::vector<int> ids)> callbackFunc;
};

class HealthListener : public Listener {
  public:
    HealthListener(std::function<void(int, int)> func);
    void notify(int id, int healthPoints) {
      callbackFunc(id, healthPoints);
    }
  private:
    std::function<void(int, int)> callbackFunc;
};

class ExhaustedListener : public Listener {
  public:
    ExhaustedListener(std::function<void(int, int)> func);
    void notify(int id, bool is_exhausted) {
      callbackFunc(id, is_exhausted);
    }
  private:
    std::function<void(int, int)> callbackFunc;
};

class DeathListener : public Listener {
  public:
    DeathListener(std::function<void(int, int)> func);
    void notify(int id, bool is_dead) {
      callbackFunc(id, is_dead);
    }
  private:
    std::function<void(int, int)> callbackFunc;
};

class ThirstListener : public Listener {
  public:
    ThirstListener(std::function<void(int, int)> func);
    void notify(int id, bool is_thirsty) {
      callbackFunc(id, is_thirsty);
    }
  private:
    std::function<void(int, int)> callbackFunc;
};

class OutboardListener : public Listener {
  public:
    OutboardListener(std::function<void(int)> func);
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    std::function<void(int id)> callbackFunc;
};

class TurnListener : public Listener {
  public:
    TurnListener(std::function<void(int, int)> func);
    void notify(int prev, int cur) {
      callbackFunc(prev, cur);
    }
  private:
    std::function<void(int prev, int cur)> callbackFunc;
};

class UmbrellaListener : public Listener {
  public:
    UmbrellaListener(std::function<void(int, bool)> func);
    void notify(int id, bool is) {
      callbackFunc(id, is);
    }
  private:
    std::function<void(int id, bool is)> callbackFunc;
};

class OwnerListener : public Listener {
  public:
    OwnerListener(std::function<void(int, int)> func);
    void notify(int id, int card) {
      callbackFunc(id, card);
    }
  private:
    std::function<void(int id, int card)> callbackFunc;
};

class RoundListener : public Listener {
  public:
    RoundListener(std::function<void(std::string)> func);
    void notify(std::string name) {
      callbackFunc(name);
    }
  private:
    std::function<void(std::string)> callbackFunc;
};