#pragma once

#include "card.h"

class Item : public Card{
  public:
    bool GetPosition() const;
    int GetPoints() const;

    void SetPosition(bool position);
    void SetPoints(int points);

  protected:
    bool position_;
    int points_ = 0;
};