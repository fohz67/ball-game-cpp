#pragma once

#include "Network.hpp"
#include "World.hpp"

class Server
{
public:
    Server(unsigned short port);
    void run();

private:
    Network network;
    World world;
};
