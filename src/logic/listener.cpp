#include "listener.h"

SeagullsListener::SeagullsListener(std::function<void()> func) 
    : callbackFunc(func) {}

AddCardsOnBoardListener::AddCardsOnBoardListener(std::function<void(int)> func)
    : callbackFunc(func) {}

RemoveUsedCardListener::RemoveUsedCardListener(std::function<void(int)> func)
    : callbackFunc(func) {}

RemoveNotUsedCardsListener::RemoveNotUsedCardsListener(std::function<void(std::vector<int> ids)> func)
    : callbackFunc(func) {}

HealthListener::HealthListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}

ExhaustedListener::ExhaustedListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}

DeathListener::DeathListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}

ThirstListener::ThirstListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}

OutboardListener::OutboardListener(std::function<void(int)> func)
    : callbackFunc(func) {}

TurnListener::TurnListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}

UmbrellaListener::UmbrellaListener(std::function<void(int, bool)> func)
    : callbackFunc(func) {}

OwnerListener::OwnerListener(std::function<void(int, int)> func)
    : callbackFunc(func) {}