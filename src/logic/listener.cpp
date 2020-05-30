#include "listener.h"

SeagullsListener::SeagullsListener(std::function<void()> func) 
    : callbackFunc(func) {}

AddCardsOnBoardListener::AddCardsOnBoardListener(void (*func)(int id))
    : callbackFunc(func) {}

RemoveUsedCardListener::RemoveUsedCardListener(void (*func)(int id))
    : callbackFunc(func) {}

RemoveNotUsedCardsListener::RemoveNotUsedCardsListener(void (*func)(std::vector<int> ids))
    : callbackFunc(func) {}

HealthListener::HealthListener(void (*func)(int id, int healthPoints))
    : callbackFunc(func) {}

ExhaustedListener::ExhaustedListener(void (*func)(int id, bool is_exhausted))
    : callbackFunc(func) {}

DeathListener::DeathListener(void (*func)(int id, bool is_dead))
    : callbackFunc(func) {}

ThirstListener::ThirstListener(void (*func)(int id, bool is_thirsty))
    : callbackFunc(func) {}

OutboardListener::OutboardListener(void (*func)(int id))
    : callbackFunc(func) {}

TurnListener::TurnListener(void (*func)(int id))
    : callbackFunc(func) {}