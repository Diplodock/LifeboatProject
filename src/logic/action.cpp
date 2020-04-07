#include "action.h"

Action::Action(GameState* game_state)
    :game_state_(game_state) {};

void Action::ChooseCharacterCard(int id) {
    (*game_state_).AddCharacter(id);
    (*game_state_).GetChosen(id);
}

//TODO

void takeItems(std::vector<int> id) {
}

void takeNavigationCards(int id) {

}

void chooseItem(int id) {

}

void chooseNavigationCard(int id) {

}
