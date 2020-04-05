#pragma once

#include "card.h"
#include "all_characters.h"

struct NavigationOptions {
    int seagull;
    bool thirsty_fighters;
    bool thirsty_rowers;
};

class Navigation : public Card {
  public:
    Navigation();

    int GetSeagull() const;
    bool GetThirstyFighters() const;
    bool GetThirstyRowers() const;
    int GetOutboardSize() const;
    Character* GetOutboard(int i) const;
    int GetThirsty() const;
    Character* GetThirsty(int i) const;

  private:
    NavigationOptions navigationOptions_;
    std::vector<Character*> outboard;
    std::vector<Character*> thirsty;
};
