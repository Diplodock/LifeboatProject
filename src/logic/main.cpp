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
 

int main() {
    GameState gs(6);
    ActionFactory af;
    std::function<ActionPtr(int, int, int)> constructor1 = [](int a, int b, int c) {
        TakeItemsAction action(a, b, c);
        return std::make_unique<TakeItemsAction>(action);
    };
    af.RegisterAction("TakeItemsAction", constructor1);
    std::function<ActionPtr(int, int, int)> constructor2 = [](int a, int b, int c) {
        Example action(a, b, c);
        return std::make_unique<Example>(action);
    };
    af.RegisterAction("Example", constructor2);
    std::function<ActionPtr(int, int, int)> constructor3 = [](int a, int b, int c) {
        TakeNavigationCard action(a, b, c);
        return std::make_unique<TakeNavigationCard>(action);
    };
    af.RegisterAction("TakeNavigationCard", constructor3);
    std::function<ActionPtr(int, int, int)> constructor4 = [](int a, int b, int c) {
        ChooseItem action(a, b, c);
        return std::make_unique<ChooseItem>(action);
    };
    af.RegisterAction("ChooseItem", constructor4);
    std::function<ActionPtr(int, int, int)> constructor5 = [](int a, int b, int c) {
        ChooseNavigationCard action(a, b, c);
        return std::make_unique<ChooseNavigationCard>(action);
    };
    af.RegisterAction("ChooseNavigationCard", constructor5);
    std::function<ActionPtr(int, int, int)> constructor6 = [](int a, int b, int c) {
        Row action(a, b, c);
        return std::make_unique<Row>(action);
    };
    af.RegisterAction("Row", constructor6);

}
