#ifndef LIFEBOAT_LOGIC_CARD_H_
#define LIFEBOAT_LOGIC_CARD_H_

#include <string>

class Card {
  public:
    std::string GetName() const;
    std::string GetDescription() const;
    int GetOwner() const;
    void SetName(std::string name);
    void SetDescription(std::string description);
    void SetOwner(int owner);
  protected:
    std::string name_;
    std::string description_;
    int owner_;
};

#endif // LIFEBOAT_LOGIC_CARD_H_