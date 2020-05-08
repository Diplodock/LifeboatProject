#pragma once

#include <vector>

class Listener {
  public:
    virtual void notify() = 0;
};

class SeagullsListener : public Listener {
  public:
    void notify(int number_of_seagulls) {};
};

class AddCardsOnBoardListener : public Listener {
  public:
    void notify(int id) {};
};

class RemoveUsedCardsListener : public Listener {
  public:
    void notify(int id) {};
};

class RemoveNotUsedCardsListener : public Listener {
  public:
    void notify(int id) {};
    void notify(std::vector<int> ids) {};
};

class HealthListener : public Listener {
  public:
    void notify(int id, int health_points) {};
};

class ExhaustedListener : public Listener {
  public:
    void notify(int id, bool is_exhausted) {};
};

class DeathListener : public Listener {
  public:
    void notify(int id, bool is_dead) {};
};

class ThirstListener : public Listener {
  public:
    void notify(int id, bool is_thirsty) {};
};

class OutboardListener : public Listener {
  public:
    void notify(int id) {};
};

class TurnListener : public Listener {
  public:
    void notify(int id) {};
};



