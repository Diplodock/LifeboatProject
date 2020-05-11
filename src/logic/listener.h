#pragma once

#include <vector>

class Listener {
  public:
    virtual void notify() {};
};

class SeagullsListener : public Listener {
  public:
    void SetFunction(void (*func)(int numberOfSeagulls)) {
      callbackFunc = func;
    }
    void notify(int numberOfSeagulls) {
      callbackFunc(numberOfSeagulls);
    }
    private:
      void (*callbackFunc)(int numberOfSeagulls);
};

class AddCardsOnBoardListener : public Listener {
  public:
    void SetFunction(void (*func)(int id)) {
      callbackFunc = func;
    }
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class RemoveUsedCardListener : public Listener {
  public:
    void SetFunction(void (*func)(int id)) {
      callbackFunc = func;
    }
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class RemoveNotUsedCardsListener : public Listener {
  public:
    void SetFunction(void (*func)(std::vector<int> ids)) {
      callbackFunc = func;
    }
    void notify(std::vector<int> ids) {
      callbackFunc(ids);
    }
  private:
    void (*callbackFunc)(std::vector<int> ids);
};

class HealthListener : public Listener {
  public:
    void SetFunction(void (*func)(int id, int healthPoints)) {
      callbackFunc = func;
    }
    void notify(int id, int healthPoints) {
      callbackFunc(id, healthPoints);
    }
  private:
    void (*callbackFunc)(int id, int healthPoints);
};

class ExhaustedListener : public Listener {
  public:
    void SetFunction(void (*func)(int id, bool is_exhausted)) {
      callbackFunc = func;
    }
    void notify(int id, bool is_exhausted) {
      callbackFunc(id, is_exhausted);
    }
  private:
    void (*callbackFunc)(int id, bool is_exhausted);
};

class DeathListener : public Listener {
  public:
    void SetFunction(void (*func)(int id, bool is_dead)) {
      callbackFunc = func;
    }
    void notify(int id, bool is_dead) {
      callbackFunc(id, is_dead);
    }
  private:
    void (*callbackFunc)(int id, bool is_dead);
};

class ThirstListener : public Listener {
  public:
    void SetFunction(void (*func)(int id, bool is_thirsty)) {
      callbackFunc = func;
    }
    void notify(int id, bool is_thirsty) {
      callbackFunc(id, is_thirsty);
    }
  private:
    void (*callbackFunc)(int id, bool is_thirsty);
};

class OutboardListener : public Listener {
  public:
    void SetFunction(void (*func)(int id)) {
      callbackFunc = func;
    }
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

class TurnListener : public Listener {
  public:
    void SetFunction(void (*func)(int id)) {
      callbackFunc = func;
    }
    void notify(int id) {
      callbackFunc(id);
    }
  private:
    void (*callbackFunc)(int id);
};

static SeagullsListener seagullListener;
static AddCardsOnBoardListener addOnBoardListener;
static RemoveNotUsedCardsListener rmNotUsedCardsListener;
static RemoveUsedCardListener rmUsedCardListener;
static HealthListener healthListener;
static ExhaustedListener exhaustedListener;
static DeathListener deathListener;
static ThirstListener thirstListener;
static OutboardListener outboardListener;
static TurnListener turnListener;