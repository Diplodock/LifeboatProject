#include <iostream>
#include "player.h"


int main() {
    Client client(CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string action = "TakeNavigationCard";
    client.Play(1, 33, 2, action);
}
