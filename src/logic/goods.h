#pragma once

#include "item.h"
#include "weapon.h"
#include "character.h"
#include "game_state.h"

class GameState;

class Goods : public Item {
    
};

class Water : public Goods {
  public:
    void DrinkWater(Character* thirsty);
};

class Umbrella : public Goods {
  public:
    void HoldUmbrella(Character* thirsty);
};

class FirstAidKit : public Goods {
  public:
    void HealCharacter(Character* healed);
};

class Compass : public Goods {
  public:
    void AddNavigation(GameState* current_game_state);
};

class Bait : public Goods {
  public:
    void BaitSharks(GameState* current_game_state);
};

class Lifeline : public Goods {
  public:
    void UseLifiline(Character* saved);
};