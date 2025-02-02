#include "protocol/Protocol.hpp"
#include <iostream>
#include "components/ColorServer.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/OpCodes.hpp"

Protocol& Protocol::get() {
    static Protocol instance;
    return instance;
}

void Protocol::injector(char* buffer, size_t length, SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void Protocol::handleMessage(std::shared_ptr<asio::ip::tcp::socket> client,
                             SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::JOIN: {
        smartBuffer.reset();
        smartBuffer << OpCodes::WORLD << Config::Gameplay::World::SIZE;

        if (Config::Server::DEV_MODE)
            std::cout << "World size sent: " << Config::Gameplay::World::SIZE
                      << std::endl;

        Network::get().sendToClient(client, smartBuffer);

        for (const auto& cell : CellManager::get().getAllCells()) {
            if (cell.getType() != CellType::PELLET) {
                continue;
            }

            Vector2 pos = cell.getPosition();

            smartBuffer.reset();
            smartBuffer << OpCodes::GAME_STATE << cell.getId() << pos.x << pos.y
                        << cell.getRadius()
                        << ColorServer::vecToInt(cell.getColor());

            Network::get().sendToClient(client, smartBuffer);
        }

        break;
    }
    case OpCodes::MOUSE_POSITION: {
        double mouseX, mouseY;
        smartBuffer >> mouseX >> mouseY;

        if (Config::Server::DEV_MODE)
            std::cout << "Mouse position received: " << mouseX << " " << mouseY
                      << std::endl;

        PlayerManager::get().getPlayerByClient(client)->setMousePosition(
            {mouseX, mouseY});

        break;
    }
    case OpCodes::KEY_PRESSED: {
        std::string keyName;
        smartBuffer >> keyName;

        if (Config::Server::DEV_MODE)
            std::cout << "Key pressed received: " << keyName << std::endl;

        // @TODO handle key pressed
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void Protocol::sendGameState() {
    SmartBuffer smartBuffer;

    for (const auto& cell : CellManager::get().getAllCells()) {
        if (cell.getType() == CellType::PELLET) {
            continue;
        }

        Vector2 pos = cell.getPosition();

        smartBuffer.reset();
        smartBuffer << OpCodes::GAME_STATE << cell.getId() << pos.x << pos.y
                    << cell.getRadius()
                    << ColorServer::vecToInt(cell.getColor());

        Network::get().sendToAll(smartBuffer);
    }

    if (Config::Server::DEV_MODE)
        std::cout << "Game state sent to everyone." << std::endl;
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;

    for (const auto& player : PlayerManager::get().getAllPlayers()) {
        Vector2 viewport = player.getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::VIEWPORT << viewport.x << viewport.y;

        if (Config::Server::DEV_MODE)
            std::cout << "Viewport sent: " << viewport.x << " " << viewport.y
                      << " to player: " << player.getId() << "." << std::endl;

        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}

void Protocol::sendEntityRemoved(const std::vector<uint32_t>& deletedIds) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::REMOVE_ENTITY;

    for (uint32_t cellId : deletedIds) {
        smartBuffer << cellId;
    }

    Network::get().sendToAll(smartBuffer);

    if (Config::Server::DEV_MODE) {
        std::cout << "Ids sent for " << deletedIds.size()
                  << " entities deleted." << std::endl;
    }
}
