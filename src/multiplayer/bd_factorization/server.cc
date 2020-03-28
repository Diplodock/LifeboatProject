#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "factorization.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::WriteOptions;
using factorization::Reply;
using factorization::Request;
using factorization::Factorization;

int foo(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}

class FactorizationImpl final : public Factorization::Service {
    Status Fact(ServerContext *context, ServerReaderWriter <Reply, Request> *stream) override {
        Request r;
        while (stream->Read(&r)) {
            int number = r.n();
            Reply reply;
            int k = foo(number);
            if (k == -1) {
                reply.set_k(1);
                reply.set_l(number);
            } else {
                reply.set_k(k);
                reply.set_l(number / k);
            }
            WriteOptions writeOptions;
            bool res = stream->Write(reply, writeOptions);
        }
        return Status::OK;
    }
};

void RunStreamServer() {
    std::string server_address("0.0.0.0:50051");
    FactorizationImpl service;
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << '\n';
    server->Wait();
}

int main() {
    RunStreamServer();
    return 0;
}
