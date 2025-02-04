#include "protocol/HandlersClient.hpp"
#include "components/ColorClient.hpp"
#include "components/Viewport.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/OpCodes.hpp"

void HandlersClient::handlePing(SmartBuffer& smartBuffer) {
    uint64_t sentTimestamp;
    smartBuffer >> sentTimestamp;

    auto     now = std::chrono::high_resolution_clock::now();
    uint64_t receivedTimestamp =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    NetworkClient::get().setPing(receivedTimestamp - sentTimestamp);
}

void HandlersClient::handleWorld(SmartBuffer& smartBuffer) {
    WorldInterface world;
    smartBuffer >> world.size;

    EntityManager::get().createWorld(world.size);
}

void HandlersClient::handlePlayer(SmartBuffer& smartBuffer) {
    PlayerInterface player;
    smartBuffer >> player.id >> player.nickname >> player.color >> player.cellColor;

    PlayerManagerClient::get().players.emplace_back(player.id,
                                                    player.nickname,
                                                    ColorClient::intToVec(player.color),
                                                    ColorClient::intToVec(player.cellColor));

    PlayerManagerClient::get().getPlayer(player.id)->setNickname(player.nickname);
}

void HandlersClient::handleCell(SmartBuffer& smartBuffer) {
    uint32_t            actualOwnerId  = 0;
    std::vector<double> actualColor    = {};
    std::string         actualNickname = "";
    long                actualMass     = 0;
    long                actualScore    = 0;
    bool                isMe           = false;

    size_t cellsNb = NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(CellInterface));

    auto* myPlayer    = PlayerManagerClient::get().getMe();
    long  myTotalMass = 0;
    long  myMaxScore  = myPlayer ? myPlayer->getScore() : 0;

    for (size_t i = 0; i < cellsNb; i++) {
        CellInterface cell;
        smartBuffer >> cell.id >> cell.ownerId >> cell.x >> cell.y >> cell.radius;

        if (cell.ownerId != actualOwnerId) {
            actualOwnerId = cell.ownerId;
            auto* player  = PlayerManagerClient::get().getPlayer(cell.ownerId);

            if (player) {
                actualColor    = player->getCellColor();
                actualNickname = player->getNickname();
            }

            actualMass = cell.radius * cell.radius / M_PI;
        } else {
            actualMass += cell.radius * cell.radius / M_PI;
        }

        if (cell.ownerId == PlayerManagerClient::get().getMyId()) {
            isMe = true;
            myTotalMass += cell.radius * cell.radius / M_PI;
            myMaxScore = std::max(myMaxScore, myTotalMass);
        }

        if (EntityManager::get().entities.find(cell.id) == EntityManager::get().entities.end()) {
            EntityManager::get().createCell(
                cell.id, cell.x, cell.y, cell.radius, actualColor, actualNickname);
        } else {
            EntityManager::get().updateCell(cell.id, cell.x, cell.y, cell.radius, true);
        }
    }

    if (isMe && myPlayer) {
        myPlayer->setMass(myTotalMass);
        myPlayer->setScore(myMaxScore);
    }
}

void HandlersClient::handlePellet(SmartBuffer& smartBuffer) {
    size_t pelletsNb = NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(PelletInterface));

    for (size_t i = 0; i < pelletsNb; i++) {
        PelletInterface cell;
        smartBuffer >> cell.id >> cell.x >> cell.y >> cell.radius >> cell.color;

        EntityManager::get().createCell(
            cell.id, cell.x, cell.y, cell.radius, ColorClient::intToVec(cell.color), "");
    }
}

void HandlersClient::handleViewport(SmartBuffer& smartBuffer) {
    ViewportInterface viewport;
    smartBuffer >> viewport.x >> viewport.y;

    Viewport::get().setViewport({viewport.x, viewport.y});
}

void HandlersClient::handleEntityRemoved(SmartBuffer& smartBuffer) {
    size_t deletedEntitiesNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(EntityInterface));

    for (size_t i = 0; i < deletedEntitiesNb; i++) {
        EntityInterface entity;
        smartBuffer >> entity.id;

        EntityManager::get().removeEntity(entity.id);
    }
}

void HandlersClient::handlePlayerDeleted(SmartBuffer& smartBuffer) {
    EntityInterface entity;
    smartBuffer >> entity.id;

    PlayerManagerClient::get().removePlayer(entity.id);
}

void HandlersClient::handleMe(SmartBuffer& smartBuffer) {
    EntityInterface entity;
    smartBuffer >> entity.id;

    PlayerManagerClient::get().setMyId(entity.id);
}
