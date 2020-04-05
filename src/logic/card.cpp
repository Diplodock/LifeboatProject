#include "card.h"

std::string Card::GetName() const {
    return cardOptions_.name;
}

std::string Card::GetDescription() const {
    return cardOptions_.description;
}

int Card::GetOwner() const {
    return cardOptions_.owner;
}

void Card::SetName(std::string new_name) {
    cardOptions_.name = new_name;
}

void Card::SetDescription(std::string new_description) {
    cardOptions_.description = new_description;
}

void Card::SetOwner(int new_owner) {
    cardOptions_.owner = new_owner;
}