#include "protocol/Send.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/OpCodes.hpp"
#include "util/ColorConverter.hpp"

const void Send::sendWorld(const std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::WORLD << Config::Gameplay::World::SIZE;

    Network::get().sendToClient(client, smartBuffer);
}

const void Send::sendPlayer(const Player& player) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PLAYER << player.getId() << player.getNickname()
                << ColorConverter::vecToInt(player.getColor())
                << ColorConverter::vecToInt(player.getCellColor());

    Network::get().sendToAll(smartBuffer);
}

const void Send::sendPlayers(const std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;

    const std::vector<Player>& players = PlayerManager::get().getPlayers();

    for (const Player& player : players) {
        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(PlayerInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToClient(client, smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::PLAYER;
        }

        smartBuffer << OpCodes::PLAYER << player.getId() << player.getNickname()
                    << ColorConverter::vecToInt(player.getColor())
                    << ColorConverter::vecToInt(player.getCellColor());
    }

    if (smartBuffer.getSize() >= sizeof(PlayerInterface) + sizeof(OpCodes)) {
        Network::get().sendToClient(client, smartBuffer);
    }
}

const void Send::sendCells() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::CELL;

    const std::vector<Cell>& cells = CellManager::get().getAllCells();

    for (const Cell& cell : cells) {
        if (cell.getType() != CellType::PLAYER) {
            continue;
        }

        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(CellInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::CELL;
        }

        const Vector2 pos = cell.getPosition();

        smartBuffer << cell.getId() << cell.getOwnerId() << pos.x << pos.y << cell.getRadius();
    }

    if (smartBuffer.getSize() >= sizeof(CellInterface) + sizeof(OpCodes)) {
        Network::get().sendToAll(smartBuffer);
    }
}

const void Send::sendPellets(const std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PELLET;

    const std::vector<Cell>& cells = CellManager::get().getAllCells();

    for (const Cell& cell : cells) {
        if (cell.getType() != CellType::PELLET) {
            continue;
        }

        if (sizeof(uint32_t) + smartBuffer.getSize() + sizeof(PelletInterface) >=
            Config::Network::MAX_SIZE) {
            Network::get().sendToClient(client, smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::PELLET;
        }

        const Vector2 pos = cell.getPosition();

        smartBuffer << cell.getId() << pos.x << pos.y << cell.getRadius()
                    << ColorConverter::vecToInt(cell.getColor());
    }

    if (smartBuffer.getSize() >= sizeof(PelletInterface) + sizeof(OpCodes)) {
        Network::get().sendToClient(client, smartBuffer);
    }
}

const void Send::sendViewport() {
    SmartBuffer smartBuffer;

    const std::vector<Player>& players = PlayerManager::get().getPlayers();

    for (const Player& player : players) {
        const Vector2 viewport = player.getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::VIEWPORT << viewport.x << viewport.y;

        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}

const void Send::sendEntityRemoved(const std::vector<uint32_t>& deletedIds) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::ENTITY_REMOVED;

    for (uint32_t cellId : deletedIds) {
        if (smartBuffer.getSize() + sizeof(EntityInterface) >= Config::Network::MAX_SIZE) {
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

const void Send::sendPlayerDeleted(const uint32_t playerId) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PLAYER_DELETED << playerId;

    Network::get().sendToAll(smartBuffer);
}

const void Send::sendMe(const std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::ME << PlayerManager::get().getPlayer(client)->getId();

    Network::get().sendToClient(client, smartBuffer);
}
