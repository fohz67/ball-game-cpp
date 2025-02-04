#include "protocol/Protocol.hpp"
#include <iostream>
#include "components/ColorServer.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/Handlers.hpp"
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
                             SmartBuffer&                           smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {

    case OpCodes::PINGPONG: {
        Handlers::handlePing(client, smartBuffer);
        break;
    }

    case OpCodes::JOIN: {
        Handlers::handleJoin(client, smartBuffer);
        break;
    }

    case OpCodes::MOUSE_POSITION: {
        Handlers::handleMousePosition(client, smartBuffer);
        break;
    }

    case OpCodes::KEY_PRESSED: {
        Handlers::handleKeyPressed(client, smartBuffer);
        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;
        break;
    }
}

void Protocol::sendPlayer(const Player& player) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PLAYER << player.getId() << player.getNickname()
                << ColorServer::vecToInt(player.getColor())
                << ColorServer::vecToInt(player.getCellColor());

    Network::get().sendToAll(smartBuffer);
}

void Protocol::sendPlayers(std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;

    const auto& players = PlayerManager::get().getAllPlayers();

    for (const auto& player : players) {
        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(PlayerInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToClient(client, smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::PLAYER;
        }

        smartBuffer << OpCodes::PLAYER << player.getId() << player.getNickname()
                    << ColorServer::vecToInt(player.getColor())
                    << ColorServer::vecToInt(player.getCellColor());
    }

    if (smartBuffer.getSize() >= sizeof(PlayerInterface) + sizeof(OpCodes)) {
        Network::get().sendToClient(client, smartBuffer);
    }
}

void Protocol::sendCells() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::CELL;

    const auto& cells = CellManager::get().getAllCells();

    for (const auto& cell : cells) {
        if (cell.getType() != CellType::PLAYER) {
            continue;
        }

        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(CellInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::CELL;
        }

        Vector2 pos = cell.getPosition();

        smartBuffer << cell.getId() << cell.getOwnerId() << pos.x << pos.y << cell.getRadius();
    }

    if (smartBuffer.getSize() >= sizeof(CellInterface) + sizeof(OpCodes)) {
        Network::get().sendToAll(smartBuffer);
    }
}

void Protocol::sendPellets(std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PELLET;

    const auto& pellets = CellManager::get().getAllCells();

    for (const auto& pellet : pellets) {
        if (pellet.getType() != CellType::PELLET) {
            continue;
        }

        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(PelletInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToClient(client, smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::PELLET;
        }

        Vector2 pos = pellet.getPosition();

        smartBuffer << pellet.getId() << pos.x << pos.y << pellet.getRadius()
                    << ColorServer::vecToInt(pellet.getColor());
    }

    if (smartBuffer.getSize() >= sizeof(PelletInterface) + sizeof(OpCodes)) {
        Network::get().sendToClient(client, smartBuffer);
    }
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;

    const auto& players = PlayerManager::get().getAllPlayers();

    for (const auto& player : players) {
        Vector2 viewport = player.getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::VIEWPORT << viewport.x << viewport.y;

        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}

void Protocol::sendEntityRemoved(const std::vector<uint32_t>& deletedIds) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::ENTITY_REMOVED;

    for (uint32_t cellId : deletedIds) {
        if (smartBuffer.getSize() + sizeof(EntityInterface) >= Config::Network::MAX_SIZE) {
            if (smartBuffer.getSize() >= Config::Network::MAX_SIZE) {
                std::cout << "Packet size exceeds maximum size" << std::endl;
            }

            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::ENTITY_REMOVED;
        }

        smartBuffer << cellId;
    }

    if (smartBuffer.getSize() >= sizeof(EntityInterface) + sizeof(OpCodes)) {
        Network::get().sendToAll(smartBuffer);
    }
}

void Protocol::sendPlayerDeleted(uint32_t playerId) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PLAYER_DELETED << playerId;

    Network::get().sendToAll(smartBuffer);
}
