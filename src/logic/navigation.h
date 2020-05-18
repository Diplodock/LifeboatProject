#pragma once

#include <memory>

#include "card.h"
#include "all_characters.h"

using CharacterPtr = std::shared_ptr<Character>;

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
    CharacterPtr GetOutboard(int i) const;
    int GetThirstySize() const;
    CharacterPtr GetThirsty(int i) const;

    void SetSeagull(int is_seagull);
    void SetThirstyFighters(bool is_thirsty_fighters);
    void SetThirstyRowers(bool is_thirsty_rowers);
    void SetOutboard(std::vector<CharacterPtr> outboard_characters);
    void SetThirsty(std::vector<CharacterPtr> thirsty_characters);

  private:
    NavigationOptions navigationOptions_;
    std::vector<CharacterPtr> outboard_;
    std::vector<CharacterPtr> thirsty_;
};