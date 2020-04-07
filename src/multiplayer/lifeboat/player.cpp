#include "player.h"

void Player::run_client(std::string user_name) {
    ClientContext context;
    std::shared_ptr<ClientReaderWriter < Request, Reply>>
    stream(stub_->Connect(&context));
    std::thread writer([stream, user_name]() {
        Request request;
        request.set_user_name(user_name);
        stream->Write(request);
        stream->WritesDone();
    });
    writer.join();
    Status status = stream->Finish();
    if (!status.ok()) std::cout << grpc_status_to_str(status);
}
