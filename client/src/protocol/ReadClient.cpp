#include "protocol/ReadClient.hpp"

#include <iostream>

#include "components/HUD.hpp"
#include "components/Leaderboard.hpp"
#include "components/Viewport.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/OpCodes.hpp"
#include "util/ColorConverterClient.hpp"

const void ReadClient::readPingPong(SmartBuffer& smartBuffer)
{
    uint64_t sentTimestamp;
    smartBuffer >> sentTimestamp;

    auto now = std::chrono::high_resolution_clock::now();
    uint64_t receivedTimestamp =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    NetworkClient::get().setPing(receivedTimestamp - sentTimestamp);
}

const void ReadClient::readCreateWorld(SmartBuffer& smartBuffer)
{
    uint16_t worldSize;
    smartBuffer >> worldSize;

    EntityManager::get().createWorld(worldSize);
}

const void ReadClient::readCreatePlayer(SmartBuffer& smartBuffer)
{
    uint32_t id, color, cellColor;
    std::string nickname;
    smartBuffer >> id >> nickname >> color >> cellColor;

    PlayerManagerClient::get().players.emplace_back(id,
                                                    nickname,
                                                    ColorConverterClient::intToVec(color),
                                                    ColorConverterClient::intToVec(cellColor));
}

const void ReadClient::readUpdateGameState(SmartBuffer& smartBuffer)
{
    const size_t cellSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;
    const size_t cellsNb = NetworkClient::get().getCutPacketSize(smartBuffer, cellSize);

    uint32_t actualOwnerId = 0;
    std::vector<double> actualColor = {};
    std::string actualNickname = "";

    for (size_t i = 0; i < cellsNb; i++)
    {
        uint32_t id, ownerId;
        double x, y, radius;
        smartBuffer >> id >> ownerId >> x >> y >> radius;

        if (ownerId != 0 && ownerId != actualOwnerId)
        {
            actualOwnerId = ownerId;

            PlayerClient* createPlayer = PlayerManagerClient::get().getPlayer(ownerId);

            if (createPlayer)
            {
                actualColor = createPlayer->getCellColor();
                actualNickname = createPlayer->getNickname();
            }
        }

        if (EntityManager::get().entities.find(id) == EntityManager::get().entities.end())
        {
            EntityManager::get().createCell(id, x, y, radius, actualColor, actualNickname);
        }
        else
        {
            EntityManager::get().updateCell(id, x, y, radius, true);
        }
    }
}

const void ReadClient::readUpdateLeaderboard(SmartBuffer& smartBuffer)
{
    const size_t leaderboardNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(std::string));

    std::vector<std::string> leaderboard;

    for (size_t i = 0; i < leaderboardNb; i++)
    {
        std::string nickname;
        smartBuffer >> nickname;

        leaderboard.push_back(nickname);
    }

    Leaderboard::get().setLeaderboard(leaderboard);
}

const void ReadClient::readSpawnPellets(SmartBuffer& smartBuffer)
{
    const size_t pelletSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;
    const size_t pelletsNb = NetworkClient::get().getCutPacketSize(smartBuffer, pelletSize);

    for (size_t i = 0; i < pelletsNb; i++)
    {
        uint32_t id, color;
        double x, y, radius;
        smartBuffer >> id >> x >> y >> radius >> color;

        EntityManager::get().createCell(
            id, x, y, radius, ColorConverterClient::intToVec(color), "");
    }
}

const void ReadClient::readUpdatePlayer(SmartBuffer& smartBuffer)
{
    double x, y;
    uint32_t score, totalMass, cellCount;
    smartBuffer >> x >> y >> score >> totalMass >> cellCount;

    Viewport::get().setViewport({x, y});

    HUD::get().setScore(score);
    HUD::get().setMass(totalMass);
    HUD::get().setCellCount(cellCount);
}

const void ReadClient::readDeleteEntity(SmartBuffer& smartBuffer)
{
    const size_t entitySize = sizeof(uint32_t);
    const size_t deletedEntitiesNb = NetworkClient::get().getCutPacketSize(smartBuffer, entitySize);

    for (size_t i = 0; i < deletedEntitiesNb; i++)
    {
        uint32_t id;
        smartBuffer >> id;

        EntityManager::get().removeEntity(id);
    }
}

const void ReadClient::readDeletePlayer(SmartBuffer& smartBuffer)
{
    uint32_t id;
    smartBuffer >> id;

    PlayerManagerClient::get().removePlayer(id);
}
