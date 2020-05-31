#pragma once

#include <string>
#include <vector>

class GameState;

struct CardOptions {
    std::string name = "";
    std::string description;
    int owner = -1;
};

class Card {
  public:
    std::string GetName() const;
    std::string GetDescription() const;
    int GetId() const;
    virtual int GetOwner() const;
    std::vector<std::string> GetAvailableActions(int player, GameState &gs) const;
    std::string GetSpecificAction() const;
    
    void SetName(std::string new_name);
    void SetDescription(std::string new_description);
    void SetId(int id);
    virtual void SetOwner(int new_owner);
    void AddAvailableAction(std::string action);
    void RemoveAvailableAction(std::string action);

  protected:
    int id_;
    std::string specific_action_;
    CardOptions cardOptions_;
    std::vector<std::string> available_actions_;
};