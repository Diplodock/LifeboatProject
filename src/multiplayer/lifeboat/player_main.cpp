#include "player.h"

int main() {
    Client client(CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.Play(1, 0, 2, "TakeItem");
    client.Play(2, 3, 1, "Fight");
}
