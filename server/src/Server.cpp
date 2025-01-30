#include "Server.hpp"
#include <iostream>
#include "GameConfig.hpp"

Server& Server::get() {
    static Server instance;
    return instance;
}

void Server::run() {
    std::cout << "Server is running..." << std::endl;
    std::cout << "Listening on port: " << GameConfig::PORT << std::endl;
    std::cout << "World size: " << GameConfig::WORLD_WIDTH << "x"
              << GameConfig::WORLD_HEIGHT << std::endl;
    std::cout << "Max players: " << GameConfig::MAX_PLAYERS << std::endl;
    std::cout << "Player speed: " << GameConfig::PLAYER_SPEED << std::endl;
    std::cout << "Split factor: " << GameConfig::SPLIT_FACTOR << std::endl;
    Network::get().run();
}
