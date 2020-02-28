#ifndef LIFEBOAT_LOGIC_ITEM_H_
#define LIFEBOAT_LOGIC_ITEM_H_

#include "Card.h"

class Item : public Card{
  public:
    bool GetPosition();
  protected:
    bool position_;
};

#endif //LIFEBOAT_LOGIC_ITEM_H_