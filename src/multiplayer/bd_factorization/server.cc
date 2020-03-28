#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>

#include "factorization.grpc.pb.h"

using namespace grpc;
using namespace factorization;
using namespace std;

int foo(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}

class FactorizationImpl final : public Factorization::Service {
    Status FactStream(ServerContext *context, ServerReaderWriter <Reply, Request> *stream) {
        Request r;
        int number = stoi(r.n());
        while (stream->Read(&r)) {
            Reply reply;
            //cout << "I'm here";
            int k = foo(number);
            if (k == -1) {
                reply.set_k("1");
                reply.set_l(r.n());
            } else {
                reply.set_k(to_string(k));
                reply.set_l(to_string(number / k));
            }
            WriteOptions writeOptions;
            bool res = stream->Write(reply, writeOptions);
        }
        return Status::OK;
    }
};

void RunStreamServer() {
    string server_address("0.0.0.0:50051");
    FactorizationImpl service;
    ServerBuilder builder;

    builder.AddListeningPort(server_address, InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr <Server> server(builder.BuildAndStart());
    cout << "Server listening on " << server_address << endl;
    server->Wait();
}

int main() {
    RunStreamServer();
    return 0;
}
