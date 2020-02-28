#include "Character.h" 

void SetAllCharacters() {
    std::string name;
    std::string description;

    name = "Капитан";
    description = "Двойной бонус за деньги";
    Character captain(name, description, 7, 5);

    name = "Боцман";
    description = "Здоровый как чёрт";
    Character first_mate(name, description, 8, 4);

    name = "Шкет";
    description = "Карманник: может забрать любую закрытую карту без последствий";
    Character the_kid(name, description, 3, 9);

    name = "Миледи";
    description = "Двойной бонус за украшения";
    Character lady_lauren(name, description, 4, 8);

    name = "Сноб";
    description = "Двойной бонус за картины";
    Character sir_stephen(name, description, 5, 7);

    name = "Черпак";
    description = "Хорошо плавает: не получает урон при падении за борт";
    Character frenchy(name, description, 6, 6);

}