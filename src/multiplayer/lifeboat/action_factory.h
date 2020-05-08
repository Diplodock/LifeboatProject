#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <memory>
#include <unordered_map>
#include <utility>
#include <cstring>

#include "json.hpp"
#include "GenericAction.h"
#include "../../logic/action.h"
#include "../../logic/game_state.h"

using json = nlohmann::json;

using ActionPtr = std::unique_ptr<GenericAction>;

class ActionFactory {
public:
    ActionFactory() = default;

    void RegisterAction(const std::string& name, const std::function<GenericAction(int, int, int)>& constructor) {
        constructors_[name] = constructor;
    }

    ActionPtr CreateAction(const std::string& name, int user_id, int card_id, int other_user) {
        if (constructors_.find(name) == constructors_.end()) {
            throw std::runtime_error("No such action " + name);
        }
        return std::make_unique<GenericAction>(constructors_[name](user_id, card_id, other_user));
    }

private:
    std::unordered_map<std::string, std::function<GenericAction(int, int, int)>> constructors_;

};


#endif //ACTION_FACTORY_H
