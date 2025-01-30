#include "Client.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include "network/OpCodes.hpp"

Client& Client::get() {
    static Client instance;
    return instance;
}

void Client::run(const char** av) {
    std::string ip = av[1];
    unsigned short port = static_cast<unsigned short>(std::stoi(av[2]));

    CNetwork::get().init(ip, port);
    CNetwork::get().run();
    join();
    GameState::get().run();
}

void Client::join() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::JOIN);
    CNetwork::get().send(smartBuffer);
}
