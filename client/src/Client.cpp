#include "Client.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include "OpCodes.hpp"

Client::Client(const std::string& host, unsigned short port)
    : network(host, port), game_state() {}

void Client::run() {
    network.run();
    join();
    game_state.run();
}

void Client::join() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::JOIN);
    network.send(smartBuffer);
}
