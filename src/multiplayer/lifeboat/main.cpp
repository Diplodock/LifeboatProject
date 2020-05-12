#include <iostream>
#include "server.h"

void RunStreamServer() {
    std::string server_address("0.0.0.0:50051");
    GameImpl service;
    ServerBuilder builder;
    
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(reinterpret_cast<grpc::Service *>(&service));
    
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << '\n';
    server->Wait();
}

int main() {
    RunStreamServer();
}
