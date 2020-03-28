#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>

#include "factorization.grpc.pb.h"

using namespace grpc;
using namespace factorization;
using namespace std;

class FactorizationStreamClient {

public:
    FactorizationStreamClient(shared_ptr <Channel> channel) : stub_(Factorization::NewStub(channel)) {}

    void Fact(const string &n) {
        ClientContext context;
        Request request;
        unique_ptr <ClientReaderWriter<Request, Reply>> client;
        client = stub_->Fact(&context);
        request.set_n(n);
        WriteOptions options; // я не понимаю что это такое, но без этого не работает
        options.set_last_message();
        client->Write(request, options);
        Reply reply;
        while (client->Read(&reply)) { // не работает
            cout << "k = " << reply.k() << '\n';
            cout << "l = " << reply.l() << '\n';
        }
        cout << "n = " << request.n() << endl;
    }

private:
    unique_ptr <Factorization::Stub> stub_;
};

int main(int argc, char **argv) {
    FactorizationStreamClient client(CreateChannel("localhost:50051", InsecureChannelCredentials()));
    client.Fact(argv[1]);
    return 0;
}
