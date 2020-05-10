#pragma once

// #include "all_characters.h"
// #include "goods.h"
// #include "additional.h"
// #include "navigation.h"
// #include "weapon.h"
// #include "player.h"
// #include "game_state.h"
// #include "game.h"
// #include "universal.h"



// void add_cards(GameState* game_state) {

//     //items

//     Water water;
//     water.SetName("Вода");
//     water.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
//     water.SetPosition(false);
//     for (std::size_t i = 0; i < 16; i++) {
//         (*game_state).AddNotUsedItem(&water);
//     }

//     FirstAidKit first_aid_kit;
//     first_aid_kit.SetName("Аптечка");
//     first_aid_kit.SetDescription("Действие: можно убрать один маркер ранения с любого персонажа, включая вас. Сбросьте эту карту после использования.");
//     first_aid_kit.SetPosition(false);
//     for (std::size_t i = 0; i < 3; i++) {
//         (*game_state).AddNotUsedItem(&first_aid_kit);
//     }

//     Compass compass;
//     compass.SetName("Компас");
//     compass.SetDescription("Если вы сидите на корме,то добавьте одну карту из колоды навигации на навигационный стол перед тем, как начать выбирать на нём карту.");
//     compass.SetPosition(false);
//     (*game_state).AddNotUsedItem(&compass);

//     Lifeline lifeline;
//     lifeline.SetName("Спасательный круг");
//     lifeline.SetDescription("Защищает от одного ранения при падении за борт. Его можно бросить персонажу за бортом, еще находящемуся в сознании");
//     lifeline.SetPosition(false);
//     (*game_state).AddNotUsedItem(&lifeline);

//     Bait bait;
//     bait.SetName("Приманка для акул");
//     bait.SetDescription("Используйте во время навигации, чтобы приманить акул. Каждый за бортом получает по одной дополнительной ране");
//     bait.SetPosition(false);
//     for (std::size_t i = 0; i < 2; i++) {
//         (*game_state).AddNotUsedItem(&bait);
//     }

//     Umbrella umbrella;
//     umbrella.SetName("Зонтик");
//     umbrella.SetDescription("Действие: откройте зонтик. Во время каждого хода, пока он у вас в руках, вы можете защититься от одного ранения, вызванного жаждой");
//     umbrella.SetPosition(false);
//     (*game_state).AddNotUsedItem(&umbrella);

//     Paddle paddle;
//     paddle.SetName("Весло");
//     paddle.SetDescription("");
//     paddle.SetPosition(false);
//     paddle.SetPoints(1);
//     for (std::size_t i = 0; i < 2; i++) {
//         (*game_state).AddNotUsedItem(&paddle);
//     }

//     FlareGun flare_gun;
//     flare_gun.SetName("Сигнальный пистолет");
//     flare_gun.SetDescription("Можно однократно использовать как оружие или же выстрелить им в воздух, чтобы потянуть 3 карты и получить эффект от всех и сразу же получить эффект от всех увиденных птиц. Сбросьте эту карту после использования");
//     flare_gun.SetPosition(false);
//     flare_gun.SetPoints(8);
//     (*game_state).AddNotUsedItem(&flare_gun);

//     Weapon knife;
//     knife.SetName("Нож");
//     knife.SetDescription("");
//     knife.SetPosition(false);
//     knife.SetPoints(3);
//     (*game_state).AddNotUsedItem(&knife);

//     Weapon club;
//     club.SetName("Дубинка");
//     club.SetDescription("");
//     club.SetPosition(false);
//     club.SetPoints(2);
//     (*game_state).AddNotUsedItem(&club);

//     Weapon hook;
//     hook.SetName("Багор");
//     hook.SetDescription("");
//     hook.SetPosition(false);
//     hook.SetPoints(4);
//     (*game_state).AddNotUsedItem(&hook);

//     Additional money;
//     money.SetName("Пачка денег");
//     money.SetDescription("");
//     money.SetPosition(false);
//     money.SetPoints(1);
//     money.SetKind("money");
//     for (std::size_t i = 0; i < 6; i++) {
//         (*game_state).AddNotUsedItem(&money);
//     }

//     Additional jewelry;
//     jewelry.SetName("Украшения");
//     jewelry.SetDescription("");
//     jewelry.SetPosition(false);
//     jewelry.SetPoints(1);
//     jewelry.SetKind("jewelry");
//     for (std::size_t i = 0; i < 3; i++) {
//         (*game_state).AddNotUsedItem(&jewelry);
//     }

//     Additional painting;
//     painting.SetName("Картина");
//     painting.SetDescription("");
//     painting.SetPosition(false);
//     painting.SetPoints(3);
//     painting.SetKind("painting");
//     for (std::size_t i = 0; i < 2; i++) {
//         (*game_state).AddNotUsedItem(&painting);
//     }
//     painting.SetPoints(2);
// }