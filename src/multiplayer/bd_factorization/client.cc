#include <iostream>
#include <memory>
#include <string>
#include <thread>
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

std::string grpc_code_to_str(grpc::StatusCode code) {
    using sc = grpc::StatusCode;

    switch (code) {
        case sc::OK:
            return "OK";
        case sc::CANCELLED:
            return "CANCELLED";
        case sc::INVALID_ARGUMENT:
            return "INVALID_ARGUMENT";
        case sc::DEADLINE_EXCEEDED:
            return "DEADLINE_EXCEEDED";
        case sc::NOT_FOUND:
            return "NOT_FOUND";
        case sc::ALREADY_EXISTS:
            return "ALREADY_EXISTS";
        case sc::PERMISSION_DENIED:
            return "PERMISSION_DENIED";
        case sc::UNAUTHENTICATED:
            return "UNAUTHENTICATED";
        case sc::RESOURCE_EXHAUSTED:
            return "RESOURCE_EXHAUSTED";
        case sc::FAILED_PRECONDITION:
            return "FAILED_PRECONDITION";
        case sc::ABORTED:
            return "ABORTED";
        case sc::OUT_OF_RANGE:
            return "OUT_OF_RANGE";
        case sc::UNIMPLEMENTED:
            return "UNIMPLEMENTED";
        case sc::INTERNAL:
            return "INTERNAL";
        case sc::UNAVAILABLE:
            return "UNAVAILABLE";
        case sc::DATA_LOSS:
            return "DATA_LOSS";
        case sc::DO_NOT_USE:
            return "DO_NOT_USE";
        case sc::UNKNOWN:
            return "UNKNOWN";
    }

    return "UNKNOWN";
}

std::string grpc_status_to_str(const grpc::Status &status) {
    grpc::StatusCode err_code = status.error_code();
    std::string err_message = status.error_message();
    std::string err_details = status.error_details();

    return std::string("StatusCode: (") + std::to_string(err_code) + ") " + grpc_code_to_str(err_code) + "\n"
           + "Message: " + err_message + "\n"
           + "Details: " + err_details + "\n";
}

class FactorizationStreamClient {

public:
    FactorizationStreamClient(std::shared_ptr <Channel> channel) : stub_(
            factorization::Factorization::NewStub(channel)) {}

    void Fact() {
        ClientContext context;
        std::shared_ptr <ClientReaderWriter<Request, Reply>> stream(stub_->Fact(&context));
        std::thread writer([stream]() {
            int n = -1;
            std::cin >> n;
            while (n != -1) {
                Request request;
                request.set_n(n);
                stream->Write(request);
                std::cin >> n;
            }
            stream->WritesDone();
        });
        Reply reply;
        while (stream->Read(&reply)) {
            std::cout << "k = " << reply.k() << '\n';
            std::cout << "l = " << reply.l() << '\n';
        }
        writer.join();
        Status status = stream->Finish();
        if (!status.ok()) std::cout << grpc_status_to_str(status);
    }

private:
    std::unique_ptr<Factorization::Stub> stub_;
};

int main(int argc, char **argv) {
    FactorizationStreamClient client(CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.Fact();
    return 0;
}
