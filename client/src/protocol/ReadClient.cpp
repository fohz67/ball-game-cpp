#include "protocol/ReadClient.hpp"
#include "components/HUD.hpp"
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
    ICreatePlayer createPlayer;
    smartBuffer >> createPlayer.id >> createPlayer.nickname >> createPlayer.color >>
        createPlayer.cellColor;

    PlayerManagerClient::get().players.emplace_back(
        createPlayer.id,
        createPlayer.nickname,
        ColorConverterClient::intToVec(createPlayer.color),
        ColorConverterClient::intToVec(createPlayer.cellColor));

    PlayerManagerClient::get().getPlayer(createPlayer.id)->setNickname(createPlayer.nickname);
}

const void ReadClient::readUpdateGameState(SmartBuffer& smartBuffer) {
    uint32_t            actualOwnerId  = 0;
    std::vector<double> actualColor    = {};
    std::string         actualNickname = "";

    const size_t cellsNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(IUpdateGameState));

    for (size_t i = 0; i < cellsNb; i++) {
        IUpdateGameState updateGameState;
        smartBuffer >> updateGameState.id >> updateGameState.ownerId >> updateGameState.x >>
            updateGameState.y >> updateGameState.radius;

        if (updateGameState.ownerId != 0 && updateGameState.ownerId != actualOwnerId) {
            actualOwnerId = updateGameState.ownerId;

            PlayerClient* createPlayer =
                PlayerManagerClient::get().getPlayer(updateGameState.ownerId);

            if (createPlayer) {
                actualColor    = createPlayer->getCellColor();
                actualNickname = createPlayer->getNickname();
            }
        }

        if (EntityManager::get().entities.find(updateGameState.id) ==
            EntityManager::get().entities.end()) {
            EntityManager::get().createCell(updateGameState.id,
                                            updateGameState.x,
                                            updateGameState.y,
                                            updateGameState.radius,
                                            actualColor,
                                            actualNickname);
        } else {
            EntityManager::get().updateCell(updateGameState.id,
                                            updateGameState.x,
                                            updateGameState.y,
                                            updateGameState.radius,
                                            true);
        }
    }
}

const void ReadClient::readSpawnPellets(SmartBuffer& smartBuffer) {
    const size_t pelletsNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(ISpawnPellets));

    for (size_t i = 0; i < pelletsNb; i++) {
        ISpawnPellets spawnPellets;
        smartBuffer >> spawnPellets.id >> spawnPellets.x >> spawnPellets.y >> spawnPellets.radius >>
            spawnPellets.color;

        EntityManager::get().createCell(spawnPellets.id,
                                        spawnPellets.x,
                                        spawnPellets.y,
                                        spawnPellets.radius,
                                        ColorConverterClient::intToVec(spawnPellets.color),
                                        "");
    }
}

const void ReadClient::readUpdatePlayer(SmartBuffer& smartBuffer) {
    IUpdatePlayer updatePlayer;
    smartBuffer >> updatePlayer.x >> updatePlayer.y >> updatePlayer.score >>
        updatePlayer.totalMass >> updatePlayer.cellCount;

    Viewport::get().setViewport({updatePlayer.x, updatePlayer.y});

    HUD::get().setScore(updatePlayer.score);
    HUD::get().setMass(updatePlayer.totalMass);
    HUD::get().setCellCount(updatePlayer.cellCount);
}

const void ReadClient::readDeleteEntity(SmartBuffer& smartBuffer) {
    const size_t deletedEntitiesNb =
        NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(IEntity));

    for (size_t i = 0; i < deletedEntitiesNb; i++) {
        IEntity deleteEntity;
        smartBuffer >> deleteEntity.id;

        EntityManager::get().removeEntity(deleteEntity.id);
    }
}

const void ReadClient::readDeletePlayer(SmartBuffer& smartBuffer) {
    IEntity deletePlayer;
    smartBuffer >> deletePlayer.id;

    PlayerManagerClient::get().removePlayer(deletePlayer.id);
}
