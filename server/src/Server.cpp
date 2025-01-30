#include "Server.hpp"
#include "GameConfig.hpp"
#include <iostream>

Server::Server(unsigned short port)
    : network(port), world(GameConfig::WORLD_WIDTH, GameConfig::WORLD_HEIGHT) {}

void Server::run()
{
    std::cout << "Server is running..." << std::endl;
    std::cout << "Listening on port: " << network.get_port() << std::endl;
    std::cout << "World size: " << world.get_width() << "x" << world.get_height() << std::endl;
    std::cout << "Max players: " << GameConfig::MAX_PLAYERS << std::endl;
    std::cout << "Player speed: " << GameConfig::PLAYER_SPEED << std::endl;
    std::cout << "Split factor: " << GameConfig::SPLIT_FACTOR << std::endl;
    network.start();
}
