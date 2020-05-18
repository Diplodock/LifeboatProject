#include "navigation.h"

using NavigationPtr = std::shared_ptr<Navigation>;

NavigationPtr create(Navigation obj) {
    return std::make_shared<Navigation>(obj);
}

Navigation::Navigation() {
    navigationOptions_.seagull = 0;
    navigationOptions_.thirsty_fighters = false;
    navigationOptions_.thirsty_rowers = false;
}

int Navigation::GetSeagull() const {
    return  navigationOptions_.seagull;
}

bool Navigation::GetThirstyFighters() const {
    return navigationOptions_.thirsty_fighters;
}

bool Navigation::GetThirstyRowers() const {
    return navigationOptions_.thirsty_rowers;
}

int Navigation::GetOutboardSize() const {
    return outboard_.size();
}

CharacterPtr Navigation::GetOutboard(int i) const {
    return outboard_[i];
}

int Navigation::GetThirstySize() const {
    return  thirsty_.size();
}

CharacterPtr Navigation::GetThirsty(int i) const {
    return thirsty_[i];
}

void Navigation::SetSeagull(int is_seagull) {
    navigationOptions_.seagull = is_seagull;
}

void Navigation::SetThirstyFighters(bool is_thirsty_fighters) {
    navigationOptions_.thirsty_fighters = is_thirsty_fighters;
}

void Navigation::SetThirstyRowers(bool is_thirsty_rowers) {
    navigationOptions_.thirsty_rowers = is_thirsty_rowers;
}

void Navigation::SetOutboard(std::vector<CharacterPtr> outboard_characters) {
    outboard_ = outboard_characters;
}

void Navigation::SetThirsty(std::vector<CharacterPtr> thirsty_characters) {
    thirsty_ = thirsty_characters;
}

static Navigation nav1;
static Navigation nav2;
static Navigation nav3;
static Navigation nav4;
static Navigation nav5;
static Navigation nav6;
static Navigation nav7;
static Navigation nav8;
static Navigation nav9;
static Navigation nav10;
static Navigation nav11;
static Navigation nav12;
static Navigation nav13;
static Navigation nav14;
static Navigation nav15;
static Navigation nav16;
static Navigation nav17;
static Navigation nav18;
static Navigation nav19;
static Navigation nav20;
static Navigation nav21;
static Navigation nav22;
static Navigation nav23;
static Navigation nav24;
static Navigation nav25;
static Navigation nav26;
static Navigation nav27;
static Navigation nav28;
static Navigation nav29;

std::vector<NavigationPtr> listNav =
    {create(nav1), create(nav2), create(nav3), create(nav4), create(nav5),
    create(nav6), create(nav7), create(nav8), create(nav9), create(nav10),
    create(nav11), create(nav12), create(nav13), create(nav14), create(nav15),
    create(nav16), create(nav17), create(nav18), create(nav19), create(nav20),
    create(nav21), create(nav22), create(nav23), create(nav24), create(nav25),
    create(nav26), create(nav27), create(nav28), create(nav29)
    };