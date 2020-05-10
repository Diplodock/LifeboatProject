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
//
//
//int main() {
//    Game game;
//    game.start();
//}
#include <iostream>
#include "action_factory.h"

int main() {
    GameState gs(6);
    ActionFactory af;
    std::string action = "TakeNavigationCard";
    std::function<ActionPtr(int, int, int)> constructor = [](int a, int b, int c) {
        TakeNavigationCard action(a, b, c);
        return std::make_unique<TakeNavigationCard>(action);
    };
    af.RegisterAction(action, constructor);
    std::shared_ptr p = af.CreateAction(action, 1, 0, 2);
    std::cout << p->GetId() << '\n' << p->GetPlayer() << '\n';
    std::cout << gs.GetCard(0)->GetName();
    std::cout << gs.GetSizeOfChoice();
}
