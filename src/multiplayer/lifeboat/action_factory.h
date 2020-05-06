#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <cstring>
#include <json.hpp>

#include "../../logic/game_state.h"

using json = nlohmann::json;

class ActionFactory {
public:

    ActionFactory(json action, char* str, int user_id, json character, GameState& gs);

    std::unique_ptr<GenericAction> RegisterAction();

    int GetCardId();

    int GetCharacterId();

    int GetUserId();

    std::string GetAction();

private:
    json action_;

    char* str_;

    int user_id_;

    json character_;

    GameState gs_;

};

#endif //ACTION_FACTORY_H
