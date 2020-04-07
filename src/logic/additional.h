#pragma once

#include "item.h"

class Additional : public Item {
  public:

    std::string GetKind() const;

    void SetKind(std::string kind);
    
  private:

    int points_;
    std::string kind_;
};