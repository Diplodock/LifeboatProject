cmake_minimum_required(VERSION 3.3)
project(grpc_factorization)

find_package(Protobuf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(PROTO "${CMAKE_CURRENT_SOURCE_DIR}/factorization.proto")

set(PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/factorization.pb.cc")
set(PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/factorization.pb.h")
set(GRPC_PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/factorization.grpc.pb.cc")
set(GRPC_PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/factorization.grpc.pb.h")
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

add_executable(server_bd server.cc ${GENERATED_PROTOBUF_FILES})
add_executable(client_bd client.cc ${GENERATED_PROTOBUF_FILES})