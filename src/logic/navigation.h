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
    int GetThirstySize() const;
    Character* GetThirsty(int i) const;

    void SetSeagull(int is_seagull);
    void SetThirstyFighters(bool is_thirsty_fighters);
    void SetThirstyRowers(bool is_thirsty_rowers);
    void SetOutboard(std::vector<Character*> outboard_characters);
    void SetThirsty(std::vector<Character*> thirsty_characters);

  private:
    NavigationOptions navigationOptions_;
    std::vector<Character*> outboard_;
    std::vector<Character*> thirsty_;
};
