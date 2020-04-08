#include "player.h"

Character* Player::GetCharacter() const {
    return character_;
}

void Player::SetCharacter(Character* character) {
    character_ = character;
}