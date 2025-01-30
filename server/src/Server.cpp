#include "Server.hpp"
#include <iostream>
#include "config/Config.hpp"
#include "cell/CellManager.hpp"
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
        for (const auto& player : PlayerManager::get().getAllPlayers()) {
            CellManager::get().updateCellMovement(player.getId(), player.getMouseX(), player.getMouseY());            
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}
