#include "action.h"
#include "action_factory.h"

ActionFactory::ActionFactory(json action, std::string str, int user_id, json character) {
    action_ = action;
    str_ = str;
    user_id_ = user_id;
    character_ = character;
}

std::unique_ptr <GenericAction> ActionFactory::RegisterAction() {
    if (!strcmp(str_, "ChooseCharacterCard")) {
        int id = std::stoi(action_["cards"]["id"]);
        auto gen_action = std::unique_ptr<ChooseCharacterCard>(new ChooseCharacterCard(user_id_, id));
        return gen_action;
    }
    if (!strcmp(str_, "ChooseItem")) {
        int id = std::stoi(action_["cards"]["id"]);
        auto gen_action = std::unique_ptr<ChooseItem>(new ChooseItem(user_id_, id))
        return gen_action;
    }
    if (!strcmp(str_, "ChooseNavigationCard")) {
        int id = std::stoi(action_["cards"]["id"]);
        auto gen_action = std::unique_ptr<ChooseNavigationCard>(new ChooseNavigationCard(user_id_, id));
        return gen_action;
    }
    if (!strcmp(str_, "Row")) {
        auto gen_action = std::unique_ptr<Row>(new Row(user_id_));
        return gen_action;
    }
    if (!strcmp(str_, "Fight")) {
        auto gen_action = std::unique_ptr<Fight>(new Row(user_id_));
        return gen_action;
    }
    if (!strcmp(str_, "TryToSwap")) {
        int id = std::stoi(action_["cards"]["id"]);
        auto gen_action = std::unique_ptr<TryToSwap>(new TryToSwap(user_id_, id))
        return gen_action;
    }
    if (!strcmp(str_, "TryToTakeGoods")) {
        int id = std::stoi(action_["cards"]["id"]);
        int character_id = std::stoi(character_["cards"]]["id"]);
        auto gen_action = std::unique_ptr<TryToTakeGoods>(new TryToTakeGoods(user_id_, id, character_id));
        return gen_action;
    }
    if (!strcmp(str_, "TryToGiveGoods")) {
        int id = std::stoi(action_["cards"]["id"]);
        int character_id = std::stoi(character_["cards"]["id"]);
        auto gen_action = std::unique_ptr<TryToGiveGoods>(new TryToGiveGoods(user_id_, id, character_id));
        return gen_action;
    }
}

int GetCardId() {
    int card_id = std::stoi(action_["cards"]["id"]);
    return card_id;
}

int ActionFactory::GetCharacterId() {
    int character_id = std::stoi(character_["cards"]["id"]);
    return character_id;
}

int ActionFactory::GetUserId() {
    return user_id_;
}

std::string ActionFactory::GetAction() {
    return action_;
}