#include "protocol/Read.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/Send.hpp"

const void Read::readPing(const std::shared_ptr<asio::ip::tcp::socket> client,
                          SmartBuffer&                                 smartBuffer) {
    Network::get().sendToClient(client, smartBuffer);
}

const void Read::readJoin(const std::shared_ptr<asio::ip::tcp::socket> client,
                          SmartBuffer&                                 smartBuffer) {
    JoinInterface joinInterface;
    smartBuffer >> joinInterface.nickname;

    Player player = *PlayerManager::get().getPlayer(client);
    player.setNickname(joinInterface.nickname);

    Send::sendMe(client);
    Send::sendPlayer(player);
    Send::sendPlayers(client);

    CellManager::get().createCell(player.getId());

    Send::sendWorld(client);
    Send::sendPellets(client);
}

const void Read::readMousePosition(const std::shared_ptr<asio::ip::tcp::socket> client,
                                   SmartBuffer&                                 smartBuffer) {
    MousePositionInterface mousePositionInterface;
    smartBuffer >> mousePositionInterface.x >> mousePositionInterface.y;

    PlayerManager::get().getPlayer(client)->setMousePosition(
        Vector2(mousePositionInterface.x, mousePositionInterface.y));
}

const void Read::readKeyPressed(const std::shared_ptr<asio::ip::tcp::socket> client,
                                SmartBuffer&                                 smartBuffer) {
    KeyPressedInterface keyPressedInterface;
    smartBuffer >> keyPressedInterface.key;

    // @TODO Implement key press handling
}
