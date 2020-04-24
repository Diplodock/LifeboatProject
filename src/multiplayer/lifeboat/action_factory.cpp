#include "../../logic/action.h"
#include "action_factory.h"

#include <string>
#include <cstring>
#include <utility>
#include <memory>

ActionFactory::ActionFactory(json action, char* str, int user_id, json character) {
    action_ = std::move(action);
    str_ = str;
    user_id_ = user_id;
    character_ = std::move(character);
}

std::unique_ptr<GenericAction> ActionFactory::RegisterAction() {
    if (!strcmp(str_, "ChooseCharacterCard")) {
        int id = action_["cards"]["id"];
        ChooseCharacterCard action(user_id_, id);
        return std::make_unique<ChooseCharacterCard>(action);
    }
    if (!strcmp(str_, "ChooseItem")) {
        int id = action_["cards"]["id"];
        ChooseItem action(user_id_, id);
        return std::make_unique<ChooseItem>(action);
    }
    if (!strcmp(str_, "ChooseNavigationCard")) {
        int id = action_["cards"]["id"];
        ChooseNavigationCard action(user_id_, id);
        return std::make_unique<ChooseNavigationCard>(action);
    }
    if (!strcmp(str_, "Row")) {
        Row action(user_id_);
        return std::make_unique<Row>(action);
    }
    if (!strcmp(str_, "Fight")) {
        int id = action_["cards"]["id"];
        Fight action(user_id_, id);
        return std::make_unique<Fight>(action);
    }
    if (!strcmp(str_, "TryToSwap")) {
        int id = action_["cards"]["id"];
        TryToSwap action(user_id_, id);
        return std::make_unique<TryToSwap>(action);
    }
    if (!strcmp(str_, "TryToTakeGoods")) {
        int id = action_["cards"]["id"];
        int character_id = character_["cards"]["id"];
        TryToTakeGoods action(user_id_, id, character_id);
        return std::make_unique<TryToTakeGoods>(action);
    }
    if (!strcmp(str_, "TryToGiveGoods")) {
        int id = action_["cards"]["id"];
        int character_id = character_["cards"]["id"];
        TryToGiveGoods action(user_id_, id, character_id);
        return std::make_unique<TryToGiveGoods>(action);
    }
}

int ActionFactory::GetCardId() {
    int card_id = action_["cards"]["id"];
    return card_id;
}

int ActionFactory::GetCharacterId() {
    int character_id = character_["cards"]["id"];
    return character_id;
}

int ActionFactory::GetUserId() {
    return user_id_;
}

std::string ActionFactory::GetAction() {
    return action_;
}