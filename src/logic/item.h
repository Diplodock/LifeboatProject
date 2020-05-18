#pragma once

#include "card.h"
#include "action.h"

#include <memory>
#include <vector>

class Item : public Card {
  public:
    bool GetPosition() const;
    int GetPoints() const;

    void SetPosition(bool position);
    void SetPoints(int points);

    virtual std::unique_ptr<GenericAction> GetAction(int player) {return nullptr;}
    virtual std::unique_ptr<GenericAction> GetAction(int player, int saved) {return nullptr;}
    virtual std::unique_ptr<GenericAction> GetAction() {return nullptr;}

    int GetPlayer() const;
    void SetPlayer(int player);

  protected:
    bool position_;
    int points_ = 0;
    int player_;
};