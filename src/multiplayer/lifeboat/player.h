#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <grpc++/grpc++.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "lifeboat.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc_impl::ClientReader;
using grpc_impl::ClientReaderWriter;
using grpc_impl::ClientWriter;
using grpc::Status;
using grpc::WriteOptions;
using lifeboat::Reply;
using lifeboat::Request;
using lifeboat::Game;
using lifeboat::UserNameMessage;
using lifeboat::UserIdMessage;


class Client {
public:
    Client(std::shared_ptr<Channel> channel) : stub_(
                                                     lifeboat::Game::NewStub(channel)) {}
    
    void Play(int user_id, int card_id, int other_user_id, const std::string &action);
    
    // void RegistratePlayer(const std::string &user_name);
    
private:
    std::unique_ptr<Game::Stub> stub_;
    
    std::string grpc_status_to_str(const grpc::Status &status);
    
    std::string grpc_code_to_str(grpc::StatusCode code);
};

