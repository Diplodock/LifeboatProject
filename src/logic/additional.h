#pragma once

#include "item.h"

class Additional : public Item {
  public:

    int GetPoints();
    std::string GetKind();
    
  private:

    int points_;
    std::string kind_;
};