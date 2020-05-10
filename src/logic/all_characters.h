#pragma once

#include "character.h"

class Captain : public Character {
  public:
    Captain();
  private:
};

class FirstMate : public Character {
  public:
    FirstMate();
  private:
};

class TheKid : public Character {
  public:
    TheKid();
  private:
};

class LadyLauren : public Character {
  public:
    LadyLauren();
  private:
};

class SirStephen : public Character {
  public:
    SirStephen();
  private:
};

class Frenchy : public Character {
  public:
    Frenchy();
  private:
};

class DrHarter: public Character {
  public:
    DrHarter();
  private:
};

class Wong : public Character {
  public:
    Wong();
  private:
};

static FirstMate firstMate;
static Captain captain;
static Frenchy frenchy;
static DrHarter drHarter;
static TheKid kid;
static LadyLauren ladyLauren;
static SirStephen sirStephen;
static Wong wong;