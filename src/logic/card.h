#pragma once

#include <string>

struct CardOptions {
    std::string name;
    std::string description;
    int owner;
};

class Card {
  public:
    std::string GetName() const;
    std::string GetDescription() const;
    int GetOwner() const;
    
    void SetName(std::string new_name);
    void SetDescription(std::string new_description);
    void SetOwner(int new_owner);

  protected:
    CardOptions cardOptions_;
};