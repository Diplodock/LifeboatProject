#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "lifeboat.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::WriteOptions;
using lifeboat::Reply;
using lifeboat::Request;
using lifeboat::Game;

class GameImpl final : public Game::Service {
    Status Connect(ServerContext *context, ServerReaderWriter <Reply, Request> *stream) override {
        Request r;
        while (stream->Read(&r)) {
            std::cout << "registrate user " << r.user_name();
            Reply reply;
            WriteOptions writeOptions;
            bool res = stream->Write(reply, writeOptions);
        }
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GameImpl service;
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << '\n';
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
