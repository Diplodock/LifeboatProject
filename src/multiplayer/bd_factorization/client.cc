#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "factorization.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using grpc::WriteOptions;
using factorization::Reply;
using factorization::Request;
using factorization::Factorization;

class FactorizationStreamClient {

public:
    FactorizationStreamClient(std::shared_ptr<Channel> channel) : stub_(factorization::Factorization::NewStub(channel)) {}

    void Fact(const int &n) {
        ClientContext context;
        Request request;
        std::unique_ptr<ClientReaderWriter<Request, Reply>> client;
        client = stub_->Fact(&context);
        request.set_n(n);
        WriteOptions options;
        options.set_last_message();
        client->Write(request, options);
        client->WritesDone();
        Reply reply;
        while (client->Read(&reply)) {
            std::cout << "k = " << reply.k() << '\n';
            std::cout << "l = " << reply.l() << '\n';
        }
        std::cout << "n = " << request.n() << '\n';
        Status status = client->Finish();
        if (!status.ok()) std::cout << "failed";
    }

private:
    std::unique_ptr<Factorization::Stub> stub_;
};

int main(int argc, char **argv) {
    FactorizationStreamClient client(CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.Fact(std::stoi(argv[1]));
    return 0;
}
