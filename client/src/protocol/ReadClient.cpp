#include "protocol/ReadClient.hpp"
#include "components/Viewport.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/OpCodes.hpp"
#include "util/ColorConverterClient.hpp"

const void ReadClient::readPingPong(SmartBuffer& smartBuffer) {
    uint64_t sentTimestamp;
    smartBuffer >> sentTimestamp;

    auto     now = std::chrono::high_resolution_clock::now();
    uint64_t receivedTimestamp =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    NetworkClient::get().setPing(receivedTimestamp - sentTimestamp);
}

const void ReadClient::readCreateWorld(SmartBuffer& smartBuffer) {
    ICreateWorld world;
    smartBuffer >> world.size;

    EntityManager::get().createWorld(world.size);
}

const void ReadClient::readCreatePlayer(SmartBuffer& smartBuffer) {
    ICreatePlayer player;
    smartBuffer >> player.id >> player.nickname >> player.color >> player.cellColor;

    PlayerManagerClient::get().players.emplace_back(
        player.id,
        player.nickname,
        ColorConverterClient::intToVec(player.color),
        ColorConverterClient::intToVec(player.cellColor));

    PlayerManagerClient::get().getPlayer(player.id)->setNickname(player.nickname);
}

const void ReadClient::readUpdateGameState(SmartBuffer& smartBuffer) {
    uint32_t            actualOwnerId  = 0;
    std::vector<double> actualColor    = {};
    std::string         actualNickname = "";

    const size_t cellsNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(IUpdateGameState));

    for (size_t i = 0; i < cellsNb; i++) {
        IUpdateGameState cell;
        smartBuffer >> cell.id >> cell.ownerId >> cell.x >> cell.y >> cell.radius;

        if (cell.ownerId != actualOwnerId) {
            actualOwnerId = cell.ownerId;

            PlayerClient* player = PlayerManagerClient::get().getPlayer(cell.ownerId);

            if (player) {
                actualColor    = player->getCellColor();
                actualNickname = player->getNickname();
            }
        }

        if (EntityManager::get().entities.find(cell.id) == EntityManager::get().entities.end()) {
            EntityManager::get().createCell(
                cell.id, cell.x, cell.y, cell.radius, actualColor, actualNickname);
        } else {
            EntityManager::get().updateCell(cell.id, cell.x, cell.y, cell.radius, true);
        }
    }
}

const void ReadClient::readSpawnPellets(SmartBuffer& smartBuffer) {
    const size_t pelletsNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(ISpawnPellets));

    for (size_t i = 0; i < pelletsNb; i++) {
        ISpawnPellets cell;
        smartBuffer >> cell.id >> cell.x >> cell.y >> cell.radius >> cell.color;

        EntityManager::get().createCell(
            cell.id, cell.x, cell.y, cell.radius, ColorConverterClient::intToVec(cell.color), "");
    }
}

const void ReadClient::readUpdatePlayer(SmartBuffer& smartBuffer) {
    IUpdatePlayer viewport;
    smartBuffer >> viewport.x >> viewport.y;

    Viewport::get().setViewport({viewport.x, viewport.y});
}

const void ReadClient::readDeleteEntity(SmartBuffer& smartBuffer) {
    const size_t deletedEntitiesNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(IEntity));

    for (size_t i = 0; i < deletedEntitiesNb; i++) {
        IEntity entity;
        smartBuffer >> entity.id;

        EntityManager::get().removeEntity(entity.id);
    }
}

const void ReadClient::readDeletePlayer(SmartBuffer& smartBuffer) {
    IEntity player;
    smartBuffer >> player.id;

    PlayerManagerClient::get().removePlayer(player.id);
}
