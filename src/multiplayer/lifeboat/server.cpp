#include "server.h"

int count_clients = 0;

int assign_id() {
    return ::count_clients++;
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

void Server::RunServer() {
    /*std::string server_address("0.0.0.0:50051");
    GameImpl service;
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << '\n';
    server->Wait();*/
}
