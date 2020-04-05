#pragma once

#include "card.h"

class Item : public Card{
  public:
    bool GetPosition() const;
    virtual int GetPoints() const;

  protected:
    bool position_;
};