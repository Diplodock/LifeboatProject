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
    return outboard_.size();
}

Character* Navigation::GetOutboard(int i) const {
    return outboard_[i];
}

int Navigation::GetThirstySize() const {
    return  thirsty_.size();
}

Character* Navigation::GetThirsty(int i) const {
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

void Navigation::SetOutboard(std::vector<Character*> outboard_characters) {
    outboard_ = outboard_characters;
}

void Navigation::SetThirsty(std::vector<Character*> thirsty_characters) {
    thirsty_ = thirsty_characters;
}