#include "Server.hpp"
#include <iostream>
#include "config/Config.hpp"
#include "engine/Game.hpp"
#include "engine/Network.hpp"

Server& Server::get() {
    static Server instance;
    return instance;
}

void Server::run() {
    std::cout << "Server is running on port " << Config::Network::PORT << std::endl;

    Game::get().run();
    Network::get().run();
}
