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

static Navigation nav1;
static Navigation nav2;
static Navigation nav3;
static Navigation nav4;
static Navigation nav5;
static Navigation nav6;
static Navigation nav7;
static Navigation nav8;
static Navigation nav9;
static Navigation nav10;
static Navigation nav11;
static Navigation nav12;
static Navigation nav13;
static Navigation nav14;
static Navigation nav15;
static Navigation nav16;
static Navigation nav17;
static Navigation nav18;
static Navigation nav19;
static Navigation nav20;
static Navigation nav21;
static Navigation nav22;
static Navigation nav23;
static Navigation nav24;
static Navigation nav25;
static Navigation nav26;
static Navigation nav27;
static Navigation nav28;
static Navigation nav29;