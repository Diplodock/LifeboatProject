#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "lifeboat.grpc.pb.h"
#include "action_factory.h"

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
using lifeboat::UserNameMessage;
using lifeboat::UserIdMessage;

int count_clients = 0;

int assign_id() {
    return ::count_clients++;
}

class Server {
public:

    void RunServer() {
        /*std::string server_address("0.0.0.0:50051");
        GameImpl service;
        ServerBuilder builder;

        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        builder.RegisterService(&service);

        std::unique_ptr<Server> server(builder.BuildAndStart());
        std::cout << "Server listening on " << server_address << '\n';
        server->Wait();*/
    }

    class GameImpl final : public Game::Service {
        Status Registrate(ServerContext *context, ServerReaderWriter<UserNameMessage, UserIdMessage> *stream) override {
            UserNameMessage name;
            while (stream->Read(&name)) {
                name.user_name();
                UserIdMessage id;
                id.set_usser_id(assign_id());
                WriteOptions writeOptions;
                bool res = stream->Write(id, writeOptions);
            }
            return Status::OK;
        }

        Status Play(ServerContext *context, ServerReaderWriter<Request, Reply> *stream) override {
            Request r;
            while (stream->Read(&r)) {
                int user_id = r.user_id();
                int card_id = r.card_id();
                int character_id = r.character_id();
                std::string action = r.action();
                Reply reply;
                WriteOptions writeOptions;
                bool res = stream->Write(reply, writeOptions);
            }
            return Status::OK;
        }
    };

};
