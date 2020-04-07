
cmake_minimum_required(VERSION 3.3)
project(grpc_helloworld)

find_package(Protobuf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(HELLOWORLD_PROTO "${CMAKE_CURRENT_SOURCE_DIR}/helloworld.proto")

set(HELLOWORLD_PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.cc")
set(HELLOWORLD_PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.h")
set(HELLOWORLD_GRPC_PB_CPP_FILE "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
set(HELLOWORLD_GRPC_PB_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")
add_custom_command(
    OUTPUT "${HELLOWORLD_PB_H_FILE}"
           "${HELLOWORLD_PB_CPP_FILE}"
           "${HELLOWORLD_GRPC_PB_H_FILE}"
           "${HELLOWORLD_GRPC_PB_CPP_FILE}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "--proto_path=${CMAKE_CURRENT_SOURCE_DIR}"
         "--cpp_out=${CMAKE_CURRENT_BINARY_DIR}"
         "${HELLOWORLD_PROTO}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "--proto_path=${CMAKE_CURRENT_SOURCE_DIR}"
         "--grpc_out=${CMAKE_CURRENT_BINARY_DIR}"
         "--plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin"
         "${HELLOWORLD_PROTO}"
    )
set(GENERATED_PROTOBUF_FILES ${HELLOWORLD_PB_H_FILE} ${HELLOWORLD_PB_CPP_FILE}
    ${HELLOWORLD_GRPC_PB_H_FILE} ${HELLOWORLD_GRPC_PB_CPP_FILE})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
link_libraries(grpc grpc++ grpc++_unsecure protobuf grpc++_reflection ${PROTOBUF_LIBRARY})

add_executable(greeter_server greeter_server.cc ${GENERATED_PROTOBUF_FILES})
add_executable(greeter_client greeter_client.cc ${GENERATED_PROTOBUF_FILES})