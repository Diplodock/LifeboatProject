#ifndef LIFEBOAT_LOGIC_ADDITIONAL_H_
#define LIFEBOAT_LOGIC_ADDITIONAL_H_

#include "Item.h"

class Additional : public Item {
  public:
    Additional(int points);
    int GetPoints();
    
  private:
    int points_;
};

#endif //LIFEBOAT_LOGIC_ADDITIONAL_H_