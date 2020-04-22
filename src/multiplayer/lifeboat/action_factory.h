#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <cstirng>

using json = nlohmann::json;

class ActionFactory {
public:

    ActionFactory(json action, std::string str, int user_id, json character);

    std::unique_ptr<GenericAction> RegisterAction();

    int GetCardId();

    int GetCharacterId();

    int GetUserId();

    std::string GetAction();

private:
    json action_;

    std::string str_;

    int user_id_;

    json character_;

};

#endif //ACTION_FACTORY_H
