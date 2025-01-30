#include "Server.hpp"
#include <iostream>
#include "cell/CellManager.hpp"
#include "config/Config.hpp"
#include "player/PlayerManager.hpp"

Server& Server::get() {
    static Server instance;
    return instance;
}

void Server::run() {
    std::cout << "Server is running on port " << Config::Network::PORT
              << std::endl;
    std::thread updateThread(&Server::updateLoop, this);
    Network::get().run();
}

void Server::updateLoop() {
    while (true) {
        PlayerManager::get().updatePlayers();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}
