#pragma once

#include <string>
#include <vector>

class GameState;

struct CardOptions {
    std::string name;
    std::string description;
    int owner;
};

class Card {
  public:
    Card();
    std::string GetName() const;
    std::string GetDescription() const;
    virtual int GetOwner() const;
    std::vector<std::string> GetAvailableActions(int player, GameState &gs) const;
    
    void SetName(std::string new_name);
    void SetDescription(std::string new_description);
    virtual void SetOwner(int new_owner);
    void AddAvailableAction(std::string action);
    void RemoveAvailableAction(std::string action);

  protected:
    CardOptions cardOptions_;
    std::vector<std::string> available_actions_;
};