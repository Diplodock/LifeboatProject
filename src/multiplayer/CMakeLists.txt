cmake_minimum_required(VERSION 3.15)
project(lifeboat)

add_subdirectory(helloworld)
add_subdirectory(bd_factorization)
add_subdirectory(lifeboat)

add_library(
        multiplayer
        lifeboat/player.cpp
        lifeboat/action_factory.cpp
        lifeboat/action_factory.h
        lifeboat/server.cpp
        )

target_link_libraries(multiplayer grpc grpc++ grpc++_unsecure protobuf grpc++_reflection ${PROTOBUF_LIBRARY})

#add_executable(main lifeboat/main.cpp ../../util/json.hpp ../logic/action.h ../logic/action.cpp)
#target_link_libraries(main multiplayer logic)

include_directories(../../util)