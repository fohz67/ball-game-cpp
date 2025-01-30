#include "Client.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include "network/OpCodes.hpp"

Client& Client::get() {
    static Client instance;
    return instance;
}

void Client::run() {
    CNetwork::get().init();
    CNetwork::get().run();
    join();
    GameState::get().run();
}

void Client::join() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::JOIN);
    CNetwork::get().send(smartBuffer);
}
