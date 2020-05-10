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

static Additional painting1;
static Additional painting2;
static Additional painting3;

static Additional money1;
static Additional money2;
static Additional money3;
static Additional money4;
static Additional money5;
static Additional money6;

static Additional jewelry1;
static Additional jewelry2;
static Additional jewelry3;