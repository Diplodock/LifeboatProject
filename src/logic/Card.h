#ifndef LIFEBOAT_LOGIC_CARD_H_
#define LIFEBOAT_LOGIC_CARD_H_

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
    
    void SetName(std::string name);
    void SetDescription(std::string description);
    void SetOwner(int owner);

  protected:
    CardOptions cardOptions_;
};

#endif // LIFEBOAT_LOGIC_CARD_H_