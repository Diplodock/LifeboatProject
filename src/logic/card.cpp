#include "card.h"

#include "game_state.h"

using NavigationPtr = std::shared_ptr<Navigation>;


std::string Card::GetName() const {
    return cardOptions_.name;
}

std::string Card::GetDescription() const {
    return cardOptions_.description;
}

int Card::GetId() const {
    return id_;
}

int Card::GetOwner() const {
    return cardOptions_.owner;
}

std::vector<std::string> Card::GetAvailableActions(int player, GameState &gs) const {
    if (cardOptions_.owner != -1) {
        if (player != cardOptions_.owner) {
            return {};
        }
    }
    return available_actions_;
}

void Card::SetName(std::string new_name) {
    cardOptions_.name = new_name;
}

void Card::SetDescription(std::string new_description) {
    cardOptions_.description = new_description;
}

void Card::SetId(int id) {
    id_ = id;
}

void Card::SetOwner(int new_owner) {
    cardOptions_.owner = new_owner;
}

void Card::AddAvailableAction(std::string action) {
    available_actions_.push_back(action);
}

void Card::RemoveAvailableAction(std::string action) {
    std::size_t j = 0;
    for (; j < available_actions_.size(); j++) {
        if (available_actions_[j] == action) {
            break;
        }
    }
    for (; j < available_actions_.size() - 1; j++) {
        available_actions_[j] = available_actions_[j + 1]; 
    }
}