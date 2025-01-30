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
    NetworkClient::get().init(av[1], static_cast<unsigned short>(std::stoi(av[2])));
    NetworkClient::get().run();
    join();
    GameState::get().run();
}

void Client::join() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::JOIN);
    NetworkClient::get().send(smartBuffer);
}
