#include "protocol/Send.hpp"

#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/LeaderboardManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/OpCodes.hpp"
#include "util/ColorConverter.hpp"

const void Send::sendWorld(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::CREATE_WORLD << Config::Gameplay::World::SIZE;

    Network::get().sendToClient(client, smartBuffer);
}

const void Send::sendPlayer(const Player* player)
{
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::CREATE_PLAYER << player->getId() << player->getNickname()
                << ColorConverter::vecToInt(player->getColor())
                << ColorConverter::vecToInt(player->getCellColor());

    Network::get().sendToAll(smartBuffer);
}
 
const void Send::sendPlayers(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    SmartBuffer smartBuffer;

    const std::vector<Player*> players = PlayerManager::get().getPlayers();

    for (const Player* player : players)
    {
        smartBuffer.reset();
        smartBuffer << OpCodes::CREATE_PLAYER << player->getId() << player->getNickname()
                    << ColorConverter::vecToInt(player->getColor())
                    << ColorConverter::vecToInt(player->getCellColor());

        Network::get().sendToClient(client, smartBuffer);
    }
}

const void Send::sendUpdateGameState()
{
    size_t cellSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;

    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::UPDATE_GAME_STATE;

    const std::vector<Cell*> cells = CellManager::get().getPlayerCells();

    for (const Cell* cell : cells)
    {
        if (sizeof(uint32_t) + smartBuffer.getSize() + cellSize >= Config::Network::MAX_SIZE)
        {
            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::UPDATE_GAME_STATE;
        }

        const Vector2 pos = cell->getPosition();

        smartBuffer << cell->getId() << cell->getOwnerId() << pos.x << pos.y << cell->getRadius();
    }

    if (smartBuffer.getSize() >= cellSize + sizeof(OpCodes))
    {
        Network::get().sendToAll(smartBuffer);
    }
}

const void Send::sendUpdateLeaderboard()
{
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::UPDATE_LEADERBOARD;

    const std::vector<LeaderboardEntry> leaderboard =
        LeaderboardManager::get().getClientLeaderboard();
    smartBuffer << leaderboard.size();

    for (const LeaderboardEntry& entry : leaderboard)
    {
        smartBuffer << entry.nickname;
    }

    if (smartBuffer.getSize() > sizeof(OpCodes))
    {
        Network::get().sendToAll(smartBuffer);
    }
}

const void Send::sendPellets(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    size_t pelletSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;

    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::SPAWN_PELLETS;

    const std::vector<Cell*> pellets = CellManager::get().getPelletCells();

    for (const Cell* pellet : pellets)
    {
        if (sizeof(uint32_t) + smartBuffer.getSize() + pelletSize >= Config::Network::MAX_SIZE)
        {
            Network::get().sendToClient(client, smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::SPAWN_PELLETS;
        }

        const Vector2 pos = pellet->getPosition();

        smartBuffer << pellet->getId() << pos.x << pos.y << pellet->getRadius()
                    << ColorConverter::vecToInt(pellet->getColor());
    }

    if (smartBuffer.getSize() >= pelletSize + sizeof(OpCodes))
    {
        Network::get().sendToClient(client, smartBuffer);
    }
}

const void Send::sendPellet(const uint32_t pelletId,
                            const Vector2& location,
                            const double radius,
                            const std::vector<double> color)
{
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::SPAWN_PELLET;

    smartBuffer << pelletId << location.x << location.y << radius
                << ColorConverter::vecToInt(color);

    Network::get().sendToAll(smartBuffer);
}

const void Send::sendUpdatePlayer()
{
    SmartBuffer smartBuffer;

    const std::vector<Player*> players = PlayerManager::get().getPlayers();

    for (const Player* player : players)
    {
        const Vector2 viewport = player->getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::UPDATE_PLAYER << viewport.x << viewport.y
                    << static_cast<uint32_t>(player->getScore())
                    << static_cast<uint32_t>(player->getTotalMass())
                    << static_cast<uint32_t>(player->getCellCount());

        Network::get().sendToClient(player->getClient(), smartBuffer);
    }
}

const void Send::sendEntityRemoved(const std::vector<uint32_t>& deletedIds)
{
    size_t entitySize = sizeof(uint32_t);

    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::DELETE_ENTITY;

    for (uint32_t cellId : deletedIds)
    {
        if (smartBuffer.getSize() + entitySize >= Config::Network::MAX_SIZE)
        {
            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::DELETE_ENTITY;
        }

        smartBuffer << cellId;
    }

    if (smartBuffer.getSize() >= entitySize + sizeof(OpCodes))
    {
        Network::get().sendToAll(smartBuffer);
    }
}

const void Send::sendPlayerDeleted(const uint32_t playerId)
{
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::DELETE_PLAYER << playerId;

    Network::get().sendToAll(smartBuffer);
}
