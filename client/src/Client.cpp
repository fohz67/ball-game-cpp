#include <iostream>
#include <chrono>
#include <thread>
#include "Client.hpp"
#include "OpCodes.hpp"

Client::Client(const std::string &host, unsigned short port)
    : network(host, port), game_state() {}

void Client::start()
{
    network.start();
    game_state.run();
    join();
}

void Client::join()
{
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::JOIN);
    network.send(smartBuffer);
}
