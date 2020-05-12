#include "player.h"

#include <utility>

void Client::Play(int user_id, int card_id, int other_user_id, const std::string &action) {
    ClientContext context;
    std::shared_ptr <ClientReaderWriter<Request, Reply>> stream(stub_->Play(&context));
    std::thread writer([stream, user_id, card_id, other_user_id, action]() {
        while (action == "exit") {
            Request request;
            request.set_user_id(user_id);
            request.set_card_id(card_id);
            request.set_other_user_id(other_user_id);
            request.set_action(action);
            stream->Write(request);
        }
        stream->WritesDone();
    });
    
    Reply reply;
    while (stream->Read(&reply)) {
        std::cout << "user_id: " << reply.user_id() << '\n';
        std::cout << "card_id: " << reply.card_id() << '\n';
        std::cout << "other_user_id: " << reply.other_user_id() << '\n';
        std::cout << "action: " << reply.action() << '\n';
    }
    writer.join();
    Status status = stream->Finish();
    if (!status.ok()) std::cout << grpc_status_to_str(status);
}

std::string Client::grpc_status_to_str(const grpc::Status &status) {
    grpc::StatusCode err_code = status.error_code();
    std::string err_message = status.error_message();
    std::string err_details = status.error_details();
    
    return std::string("StatusCode: (") + std::to_string(err_code) + ") " + grpc_code_to_str(err_code) + "\n"
    + "Message: " + err_message + "\n"
    + "Details: " + err_details + "\n";
}

std::string Client::grpc_code_to_str(grpc::StatusCode code) {
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

/*
 void Client::RegistratePlayer(const std::string &user_name) {
 ClientContext context;
 std::shared_ptr<ClientReaderWriter<UserNameMessage, UserIdMessage>> stream(stub_->RegistratePlayer(&context));
 std::thread writer([stream, user_name]() {
 UserNameMessage request;
 request.set_user_name(user_name);
 stream->Write(request);
 stream->WritesDone();
 });
 
 UserIdMessage reply;
 while (stream->Read(&reply)) {
 std::cout << "user_id: " << reply.user_id() << '\n';
 }
 writer.join();
 Status status = stream->Finish();
 if (!status.ok()) std::cout << grpc_status_to_str(status);
 }
 */





