#include "Card.h"

std::string Card::GetName() const {
    return name_;
}

std::string Card::GetDescription() const {
    return description_;
}

int Card::GetOwner() const {
    return owner_;
}

void Card::SetName(std::string name) {
    name_ = name;
}

void Card::SetDescription(std::string description) {
    description_ = description;
}

void Card::SetOwner(int owner) {
    owner_ = owner;
}