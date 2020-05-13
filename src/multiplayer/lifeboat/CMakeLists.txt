cmake_minimum_required(VERSION 3.3)
project(lifeboat)

find_package(Protobuf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(PROTO "${CMAKE_CURRENT_SOURCE_DIR}/lifeboat.proto")

set(PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/lifeboat.pb.cc")
set(PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/lifeboat.pb.h")
set(GRPC_PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/lifeboat.grpc.pb.cc")
set(GRPC_PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/lifeboat.grpc.pb.h")

add_custom_command(
        OUTPUT "${PB_H_FILE}"
        "${PB_CPP_FILE}"
        "${GRPC_PB_H_FILE}"
        "${GRPC_PB_CPP_FILE}"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        ARGS "--proto_path=${CMAKE_CURRENT_SOURCE_DIR}"
        "--cpp_out=${CMAKE_CURRENT_BINARY_DIR}"
        "${PROTO}"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        ARGS "--proto_path=${CMAKE_CURRENT_SOURCE_DIR}"
        "--grpc_out=${CMAKE_CURRENT_BINARY_DIR}"
        "--plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin"
        "${PROTO}"
)

set(GENERATED_PROTOBUF_FILES ${PB_H_FILE} ${PB_CPP_FILE}
        ${GRPC_PB_H_FILE} ${GRPC_PB_CPP_FILE})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
link_libraries(grpc grpc++ grpc++_unsecure protobuf grpc++_reflection ${PROTOBUF_LIBRARY})

add_executable(main main.cpp server.cpp server.h ${GENERATED_PROTOBUF_FILES}
        ../../logic/all_cards.h
        ../../logic/all_cards.cpp
        ../../logic/action.cpp
        ../../logic/action.h
        ../../logic/additional.cpp
        ../../logic/additional.h
        ../../logic/all_characters.cpp
        ../../logic/all_characters.h
        ../../logic/card.cpp
        ../../logic/card.h
        ../../logic/character.cpp
        ../../logic/character.h
        ../../logic/game_state.cpp
        ../../logic/game_state.h
        ../../logic/game.cpp
        ../../logic/game.h
        ../../logic/goods.cpp
        ../../logic/goods.h
        ../../logic/item.cpp
        ../../logic/item.h
        ../../logic/navigation.cpp
        ../../logic/navigation.h
        ../../logic/player.cpp
        ../../logic/player.h
        ../../logic/weapon.cpp
        ../../logic/weapon.h
        ../../logic/universal.cpp
        ../../logic/universal.h)
add_executable(client player_main.cpp player.h player.cpp ${GENERATED_PROTOBUF_FILES})