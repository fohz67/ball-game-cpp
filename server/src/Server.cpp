#include "Server.hpp"
#include <iostream>
#include "util/GameConfig.hpp"

Server& Server::get() {
    static Server instance;
    return instance;
}

void Server::run() {
    std::cout << "Server is running on port " << Network::get().get_port()
              << std::endl;
    Network::get().run();
}
