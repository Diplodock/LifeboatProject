#include "player.h"

using PlayerPtr = std::shared_ptr<Player>;

CharacterPtr Player::GetCharacter() const {
    return character_;
}

void Player::SetCharacter(CharacterPtr character) {
    character_ = character;
}

static Player player1;
static Player player2;
static Player player3;
static Player player4;
static Player player5;
static Player player6;
static Player player7;
static Player player8;

PlayerPtr create(Player obj) {
    return std::make_shared<Player>(obj);
}

std::vector<PlayerPtr> listPlayer = 
    {std::make_shared<Player>(player1), create(player2), create(player3), create(player4),
    create(player5), create(player6), create(player7), create(player1)
    };