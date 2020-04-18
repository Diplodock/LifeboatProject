cmake_minimum_required (VERSION 3.15)
project (lifeboat)

add_subdirectory(helloworld)
add_subdirectory(bd_factorization)
add_subdirectory(lifeboat)

add_library(multiplayer lifeboat/player.cc lifeboat/player.h lifeboat/server.cpp)