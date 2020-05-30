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
 

class Vot {
public:
    Vot(GameState &gs) : gs_(gs){}
    static void add(int a);

    void setseagul();
    GameState &gs_;
};

void Vot::add(int a) {
    std::cout << "added";
}

void Vot::setseagul() {
    std::function<void(int)> func = [](int a) {
        add(a);
    };
    SeagullsListener *seag = new SeagullsListener(func);
    gs_.AddSListener(std::make_shared<SeagullsListener>(*seag));
}


int main() {
    GameState gs(6);
    ActionFactory af;
    Vot v(gs);
    v.setseagul();
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
    ActionPtr a = af.CreateAction("Example", -1, 0, 0);
    a->exec(gs);
}
