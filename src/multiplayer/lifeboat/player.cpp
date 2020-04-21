#include <nlohmann/json.hpp>

#include "player.h"

void Player::Registrate(std::string user_name) {
    ClientContext context;
    std::shared_ptr<ClientReaderWriter < UserNameMessage, UserIdMessage>> stream(stub_->Registrate(&context));
    std::thread writer([stream, user_name]() {
        UserNameMessage request;
        request.set_user_name(user_name);
        stream->Write(request);
        stream->WritesDone();
    });
    UserIdMessage reply;
    while (stream->Read(&reply)) {
        user_id = reply.user_id();
    }
    writer.join();
    Status status = stream->Finish();
    if (!status.ok()) std::cout << grpc_status_to_str(status);
}

void Player::RunGame() {
    ClientContext context;
    std::shared_ptr<ClientReaderWriter < Request, Reply>> stream(stub_->Play(&context));
    std::thread writer([stream]() {
        ActionFactory factory;
        Request request;
        request.set_user_id(factory.GetUserId());
        request.set_card_id(factory.GetCardId());
        request.set_character_id(factory.GetCharacterId());
        request.set_action(factory.GetAction());
        stream->Write(request);
        stream->WritesDone();
    });
    writer.join();
    Status status = stream->Finish();
    if (!status.ok()) std::cout << grpc_status_to_str(status);
}

