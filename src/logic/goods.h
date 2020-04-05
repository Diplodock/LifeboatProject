#pragma once

#include "item.h"
#include "weapon.h"
#include "character.h"
#include "game_state.h"

class Goods : public Item {
    
};

class Water : public Goods {
  public:
    void drinkWater(Character* thirsty);
};

class Umbrella : public Goods {
  public:
    void useUmbrella(Character* thirsty);
};

class FirstAidKit : public Goods {
  public:
    void healCharacter(Character* healed);
};

class Compass : public Goods {
  public:
    void addNavigation(GameState* current_game_state);
};

class Bait : public Goods {
  public:
    void baitSharks(GameState* current_game_state);
};

class Paddle : public Goods, public Weapon {
  public:
    void row(GameState* current_game_state);
};

class Lifeline : public Goods {
  public:
    void useLifiline(Character* saved);
};

class FlareGun : public Goods, public Weapon {
  public:
    void addThreeNavigation(GameState* current_game_state);
};