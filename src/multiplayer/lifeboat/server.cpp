#include "server.h"

Status GameImpl::Play(ServerContext *context, ServerReaderWriter <Reply, Request> *stream) {
    Request r;
    while (stream->Read(&r)) {
        int user_id = r.user_id();
        int card_id = r.card_id();
        int other_user_id = r.other_user_id();
        std::string action = r.action();
        Reply reply;
        reply.set_user_id(user_id);
        reply.set_user_id(card_id);
        reply.set_user_id(other_user_id);
        reply.set_action(action);
        WriteOptions writeOptions;
        stream->Write(reply, writeOptions);
    }
    return Status::OK;
}

/*Status GameImpl::RegistratePlayer(ServerContext *context, ServerReaderWriter <UserNameMessage, UserIdMessage> *stream) {
 UserNameMessage r;
 while (stream->Read(reinterpret_cast<UserIdMessage *>(&r))) {
 std::string user_name = r.user_name();
 UserIdMessage reply;
 int user_id = get_user_id();
 reply.set_user_id(user_id);
 WriteOptions writeOptions;
 stream->Write(reply, writeOptions);
 }
 return Status::OK;
 }*/

int GameImpl::get_user_id() {
    return ++cnt_users;
}
