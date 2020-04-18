cmake_minimum_required(VERSION 3.10)

project(lifeboat)

set(CMAKE_CXX_STANDARD 17)

add_executable(lifeboat
        main.cpp
        action.cpp
        action.h
        additional.cpp
        all_cards.cpp
        additional.h
        all_characters.cpp
        all_characters.h
        card.cpp
        card.h
        character.cpp
        character.h
        game_state.cpp
        game_state.h
        game.cpp
        game.h
        goods.cpp
        goods.h
        item.cpp
        item.h
        navigation.cpp
        navigation.h
        player.cpp
        player.h
        weapon.cpp
        weapon.h
        universal.cpp
        universal.h
        )

add_library(logic
        action.cpp
        action.h
        additional.cpp
        all_cards.cpp
        additional.h
        all_characters.cpp
        all_characters.h
        card.cpp
        card.h
        character.cpp
        character.h
        game_state.cpp
        game_state.h
        game.cpp
        game.h
        goods.cpp
        goods.h
        item.cpp
        item.h
        navigation.cpp
        navigation.h
        player.cpp
        player.h
        weapon.cpp
        weapon.h
        universal.cpp
        universal.h
        )