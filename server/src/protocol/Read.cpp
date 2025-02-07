#include "protocol/Read.hpp"

#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/Send.hpp"

const void Read::readPingPong(const std::shared_ptr<asio::ip::tcp::socket>& client,
                              SmartBuffer& smartBuffer)
{
    Network::get().sendToClient(client, smartBuffer);
}

const void Read::readJoinServer(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                SmartBuffer& smartBuffer)
{
    IJoinServer joinInterface;
    smartBuffer >> joinInterface.nickname;

    Player* player = PlayerManager::get().getPlayer(client);

    player->setNickname(joinInterface.nickname);

    Send::sendPlayer(player);
    Send::sendPlayers(client);

    CellManager::get().createCell(player->getId());

    Send::sendWorld(client);
    Send::sendPellets(client);
}

const void Read::readUpdateMousePosition(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                         SmartBuffer& smartBuffer)
{
    IUpdateMousePosition mousePositionInterface;
    smartBuffer >> mousePositionInterface.x >> mousePositionInterface.y;

    PlayerManager::get().getPlayer(client)->setMousePosition(
        Vector2(mousePositionInterface.x, mousePositionInterface.y));
}
