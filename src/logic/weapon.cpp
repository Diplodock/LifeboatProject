#include "weapon.h"
#include "weapon.h"

using ItemPtr = std::shared_ptr<Item>;

ItemPtr createWeap(Item obj) {
    return std::make_shared<Item>(obj);
}

static Weapon knife;
static Weapon harpoon;
static Weapon club;

std::vector<ItemPtr> listWeapon = {createWeap(harpoon), createWeap(knife), createWeap(club)};