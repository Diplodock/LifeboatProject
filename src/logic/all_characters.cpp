#include "all_characters.h"
#include "character.h" 

Captain::Captain() {
    cardOptions_.name = "Капитан";
    cardOptions_.description = "Двойной бонус за деньги";
    characterOptions_.strength = 7;
    characterOptions_.survival_bonus = 5;
}

FirstMate::FirstMate() {
    cardOptions_.name = "Боцман";
    cardOptions_.description = "Здоровый как чёрт";
    characterOptions_.strength = 8;
    characterOptions_.survival_bonus = 4;
}

TheKid::TheKid() {
    cardOptions_.name = "Шкет";
    cardOptions_.description = "Карманник: может забрать любую закрытую карту без последствий";
    characterOptions_.strength = 3;
    characterOptions_.survival_bonus = 9;
}

LadyLauren::LadyLauren() {
    cardOptions_.name = "Миледи";
    cardOptions_.description = "Двойной бонус за украшения";
    characterOptions_.strength = 4;
    characterOptions_.survival_bonus = 8;
}

SirStephen::SirStephen() {
    cardOptions_.name = "Сноб";
    cardOptions_.description = "Двойной бонус за картины";
    characterOptions_.strength = 5;
    characterOptions_.survival_bonus = 7;
}

Frenchy::Frenchy() {
    cardOptions_.name = "Черпак";
    cardOptions_.description = "Хорошо плавает: не получает урон при падении за борт";
    characterOptions_.strength = 6;
    characterOptions_.survival_bonus = 6;
}