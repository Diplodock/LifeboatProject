#include "game.h"

#include <iostream>

void Game::start() {
    // GameState game_state;
    // Action action(&game_state);
    
    // LadyLauren lady_lauren;
    // game_state.AddCharacter(&lady_lauren);
    // game_state.BoundCardWithId(0, &lady_lauren);
    // game_state.AddToChoice(0);
    // SirStephen sir_stephen;
    // game_state.AddCharacter(&sir_stephen);
    // game_state.BoundCardWithId(1, &sir_stephen);
    // game_state.AddToChoice(1);
    // Captain captain;
    // game_state.AddCharacter(&captain);
    // game_state.BoundCardWithId(2, &captain);
    // game_state.AddToChoice(2);
    // FirstMate first_mate;
    // game_state.AddCharacter(&first_mate);
    // game_state.BoundCardWithId(3, &first_mate);
    // game_state.AddToChoice(3);
    // Frenchy frenchy;
    // game_state.AddCharacter(&frenchy);
    // game_state.BoundCardWithId(4, &frenchy);
    // game_state.AddToChoice(4);
    // TheKid the_kid;
    // game_state.AddCharacter(&the_kid);
    // game_state.BoundCardWithId(5, &the_kid);
    // game_state.AddToChoice(5);

    // Player A;
    // game_state.SetPlayer(&A);
    // A.SetCharacter(&lady_lauren);
    // action.ChooseCharacterCard(0, 0);
    // Player B;
    // game_state.SetPlayer(&B);
    // B.SetCharacter(&sir_stephen);
    // action.ChooseCharacterCard(1, 1);
    // Player C;
    // game_state.SetPlayer(&C);
    // C.SetCharacter(&captain);
    // action.ChooseCharacterCard(2, 2);
    // Player D;
    // game_state.SetPlayer(&D);
    // D.SetCharacter(&first_mate);
    // action.ChooseCharacterCard(3, 3);
    // Player E;
    // game_state.SetPlayer(&E);
    // E.SetCharacter(&frenchy);
    // action.ChooseCharacterCard(4, 4);
    // Player F;
    // game_state.SetPlayer(&F);
    // F.SetCharacter(&the_kid);
    // action.ChooseCharacterCard(5, 5);

    // Water water_1;
    // water_1.SetName("Вода");
    // water_1.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_1.SetPosition(false);
    // game_state.AddNotUsedItem(&water_1);
    // game_state.BoundCardWithId(6, &water_1);

    // Water water_2;
    // water_2.SetName("Вода");
    // water_2.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_2.SetPosition(false);
    // game_state.AddNotUsedItem(&water_2);
    // game_state.BoundCardWithId(7, &water_2);

    // Water water_3;
    // water_3.SetName("Вода");
    // water_3.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_3.SetPosition(false);
    // game_state.AddNotUsedItem(&water_3);
    // game_state.BoundCardWithId(8, &water_3);

    // Water water_4;
    // water_4.SetName("Вода");
    // water_4.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_4.SetPosition(false);
    // game_state.AddNotUsedItem(&water_4);
    // game_state.BoundCardWithId(9, &water_4);

    // Water water_5;
    // water_5.SetName("Вода");
    // water_5.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_5.SetPosition(false);
    // game_state.AddNotUsedItem(&water_5);
    // game_state.BoundCardWithId(10, &water_5);

    // Water water_6;
    // water_6.SetName("Вода");
    // water_6.SetDescription("Используйте для того, чтобы избежать жажды во время разыгрывания карты навигации.");
    // water_6.SetPosition(false);
    // game_state.AddNotUsedItem(&water_6);
    // game_state.BoundCardWithId(11, &water_6);

    // Navigation nav_1;
    // nav_1.SetThirstyRowers(true);
    // nav_1.SetOutboard({&first_mate});
    // nav_1.SetThirsty({&captain, &first_mate});
    // game_state.AddNotUsedNavigation(&nav_1);
    // game_state.BoundCardWithId(12, &nav_1);


    // Navigation nav_2;
    // nav_2.SetThirstyRowers(true);
    // nav_2.SetThirstyFighters(true);
    // nav_2.SetOutboard({&captain});
    // nav_2.SetThirsty({&sir_stephen});
    // game_state.AddNotUsedNavigation(&nav_2);
    // game_state.BoundCardWithId(13, &nav_2);
    
    // Navigation nav_3;
    // nav_3.SetThirstyFighters(true);
    // nav_3.SetOutboard({&frenchy});
    // nav_3.SetThirsty({&captain, &first_mate, &lady_lauren});
    // game_state.AddNotUsedNavigation(&nav_3);
    // game_state.BoundCardWithId(14, &nav_3);

    // Navigation nav_4;
    // nav_4.SetOutboard({&captain});
    // nav_4.SetThirsty({&captain});
    // game_state.AddNotUsedNavigation(&nav_4);
    // game_state.BoundCardWithId(15, &nav_4);

    // Navigation nav_5;
    // nav_5.SetSeagull(1);
    // nav_5.SetOutboard({&frenchy});
    // nav_5.SetThirsty({&captain, &first_mate, &sir_stephen});
    // game_state.AddNotUsedNavigation(&nav_5);
    // game_state.BoundCardWithId(16, &nav_5);

    // Navigation nav_6;
    // nav_6.SetSeagull(1);
    // nav_6.SetThirstyRowers(true);
    // nav_6.SetOutboard({&sir_stephen});
    // nav_6.SetThirsty({&captain, &the_kid});
    // game_state.AddNotUsedNavigation(&nav_6);
    // game_state.BoundCardWithId(17, &nav_6);

    // Navigation nav_7;
    // nav_7.SetThirstyFighters(true);
    // nav_7.SetOutboard({&sir_stephen});
    // nav_7.SetThirsty({&captain, &lady_lauren});
    // game_state.AddNotUsedNavigation(&nav_7);
    // game_state.BoundCardWithId(18, &nav_7);

    // Navigation nav_8;
    // nav_8.SetOutboard({&the_kid});
    // nav_8.SetThirsty({&captain, &first_mate, &frenchy, &lady_lauren});
    // game_state.AddNotUsedNavigation(&nav_8);
    // game_state.BoundCardWithId(19, &nav_8);

    // Navigation nav_9;
    // nav_9.SetOutboard({&sir_stephen});
    // nav_9.SetThirsty({&sir_stephen, &captain});
    // game_state.AddNotUsedNavigation(&nav_9);
    // game_state.BoundCardWithId(20, &nav_9);

    // Navigation nav_10;
    // nav_10.SetSeagull(1);
    // nav_10.SetThirstyFighters(true);
    // nav_10.SetOutboard({&captain});
    // nav_10.SetThirsty({&first_mate});
    // game_state.AddNotUsedNavigation(&nav_10);
    // game_state.BoundCardWithId(21, &nav_10);

    // Navigation nav_11;
    // nav_11.SetSeagull(1);
    // nav_11.SetThirstyFighters(true);
    // nav_11.SetOutboard({&captain});
    // nav_11.SetThirsty({&first_mate});
    // game_state.AddNotUsedNavigation(&nav_11);
    // game_state.BoundCardWithId(22, &nav_11);

    // Navigation nav_12;
    // nav_12.SetSeagull(1);
    // nav_12.SetThirstyFighters(true);
    // nav_12.SetOutboard({&captain});
    // nav_12.SetThirsty({&first_mate});
    // game_state.AddNotUsedNavigation(&nav_12);
    // game_state.BoundCardWithId(23, &nav_12);


    // action.TakeItems();
    // action.ChooseItem(0, 6);
    // action.ChooseItem(1, 7);
    // action.ChooseItem(2, 8);
    // action.ChooseItem(3, 9);
    // action.ChooseItem(4, 10);
    // action.ChooseItem(5, 11);

    // action.Row(0);
    // action.Row(1);
    // action.Row(2);
    // action.Row(3);
    // action.Row(4);
    // action.Row(5);

    // action.ChooseNavigationCard(0, 21);
}

//TODO: implement process of the game linking with ui
//remember to throw disposable items after using
// Stages of game:

// -Start
// Bounding players to their characters, friends and enemies, shuffling a deck of cards in advance
// Setting order of characters: Lady Lauren, Sir Stephen, Captain, First Mate, Frenchy, The Kid

// -Loop that continues while at least one character alive or four of seagulls are not collected yet
// Goods distribution: One player take cards for everyone except dead and characters with critical state. Then he takes one card among chosen for himself and gives remaining cards
// to the next player. Skip this stage if there's no more goods

// Actions: Player can fight, row, try to swap with somebody, try to steal someone's goods, use specific goods or skip.

// Navigation: The one closest to the deque of navigation cards chooses one card from navigation table

// -End
// Point scoring