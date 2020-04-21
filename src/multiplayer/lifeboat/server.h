#ifndef SERVER_H
#define SERVER_H

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

class Server {
public:

    void RunServer();

};



#endif //SERVER_H
