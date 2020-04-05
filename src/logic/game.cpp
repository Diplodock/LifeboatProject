#include "game.h"

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