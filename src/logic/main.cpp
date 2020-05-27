#include <functional>

#include "additional.h"
#include "all_characters.h"
#include "game_state.h"
#include "game.h"
#include "goods.h"
#include "navigation.h"
#include "player.h"
#include "weapon.h"
#include "universal.h"
#include "action.h"
#include "action_factory.h"
 
using ActionPtr = std::shared_ptr<GenericAction>;

int main() {
    GameState gs(6);
    ActionFactory af;
}