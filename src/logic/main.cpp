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
    std::cout << "removed";
}

void Vot::setseagul() {
    std::function<void(int)> func = [](int a) {
        add(a);
    };
    RemoveUsedCardListener *thirstListener = new RemoveUsedCardListener(func);
    gs_.AddRemUsedListener(std::make_shared<RemoveUsedCardListener>(*thirstListener));
}


int main() {
    GameState gs(6);
    ActionFactory af;
    Vot v(gs);
    v.setseagul();
    std::function<ActionPtr(int, int, int)> constructor1 = [](int a, int b, int c) {
        FlareGunCardAction action(a, b, c);
        return std::make_unique<FlareGunCardAction>(action);
    };
    af.RegisterAction("FlareGunCardAction", constructor1);
    // std::function<ActionPtr(int, int, int)> constructor2 = [](int a, int b, int c) {
    //     FlareGunCardAction action(a, b, c);
    //     return std::make_unique<FlareGunCardAction>(action);
    // };
    // af.RegisterAction("Example", constructor2); 
    // ItemPtr a = std::dynamic_pointer_cast<Item>(gs.GetCard(65));
    // std::cout << a->GetId();
    // ActionPtr p = af.CreateAction("FlareGunCardAction", 3, 65, 0);
    // p->exec(gs);

    CharacterPtr charact = std::dynamic_pointer_cast<Character>(gs.GetCard(2));
    charact->AddItem(std::dynamic_pointer_cast<Item>(gs.GetCard(52)), gs);
    charact->AddItem(std::dynamic_pointer_cast<Item>(gs.GetCard(44)), gs);
    std::vector<int> cur = gs.GetBackpack(2);
    for (int x : cur) {
        std::cout << x << '\n';
    }
}