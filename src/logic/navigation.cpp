#include "navigation.h"

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
    return outboard.size();
}

Character* Navigation::GetOutboard(int i) const {
    return outboard[i];
}

int Navigation::GetThirsty() const {
    return  thirsty.size();
}

Character* Navigation::GetThirsty(int i) const {
    return thirsty[i];
}