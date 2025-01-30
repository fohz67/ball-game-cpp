#include "Server.hpp"
#include <iostream>
#include "Config.hpp"

Server& Server::get() {
    static Server instance;
    return instance;
}

void Server::run() {
    std::cout << "Server is running on port " << Config::Network::PORT
              << std::endl;
    Network::get().run();
}
