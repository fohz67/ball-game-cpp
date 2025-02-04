#include "protocol/Handlers.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/Protocol.hpp"

void Handlers::handlePing(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer) {
    Network::get().sendToClient(client, smartBuffer);
}

void Handlers::handleJoin(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer) {
    std::string nickname;
    smartBuffer >> nickname;

    auto& player = *PlayerManager::get().getPlayerByClient(client);

    player.setNickname(nickname);

    Protocol::get().sendMe(client);
    Protocol::get().sendPlayer(player);
    Protocol::get().sendPlayers(client);
    CellManager::get().createCell(player.getId(), CellType::PLAYER);

    smartBuffer.reset();
    smartBuffer << OpCodes::WORLD << Config::Gameplay::World::SIZE;

    Network::get().sendToClient(client, smartBuffer);

    Protocol::get().sendPellets(client);
}

void Handlers::handleMousePosition(std::shared_ptr<asio::ip::tcp::socket> client,
                                   SmartBuffer&                           smartBuffer) {
    double mouseX;
    double mouseY;
    smartBuffer >> mouseX >> mouseY;

    PlayerManager::get().getPlayerByClient(client)->setMousePosition(Vector2(mouseX, mouseY));
}

void Handlers::handleKeyPressed(std::shared_ptr<asio::ip::tcp::socket> client,
                                SmartBuffer&                           smartBuffer) {
    std::string keyName;
    smartBuffer >> keyName;
}
