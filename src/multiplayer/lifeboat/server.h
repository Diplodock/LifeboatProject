#pragma once

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
using grpc_impl::ServerReader;
using grpc_impl::ServerAsyncReaderWriter;
using grpc_impl::ServerWriter;
using grpc_impl::ServerReaderWriter;
using grpc::Status;
using grpc::WriteOptions;
using lifeboat::Reply;
using lifeboat::Request;
using lifeboat::Game;
using lifeboat::UserNameMessage;
using lifeboat::UserIdMessage;


class GameImpl final : public Game::Service {
    Status Play(ServerContext *context, ServerReaderWriter <Reply, Request> *stream);
    
    //Status RegistratePlayer(ServerContext *context, ServerReaderWriter <UserNameMessage, UserIdMessage> *stream);
    
private:
    int get_user_id();
    
    int cnt_users = 0;
    
    ActionFactory af_;
};
