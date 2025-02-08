#include "protocol/Read.hpp"

#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
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
    std::string nickname;
    smartBuffer >> nickname;

    Player* player = PlayerManager::get().getPlayer(client);

    player->setNickname(nickname);

    Send::sendPlayer(player);
    Send::sendPlayers(client);

    CellManager::get().createCell(player->getId());

    Send::sendWorld(client);
    Send::sendPellets(client);
}

const void Read::readUpdateMousePosition(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                         SmartBuffer& smartBuffer)
{
    Vector2 mousePosition;
    smartBuffer >> mousePosition.x >> mousePosition.y;

    PlayerManager::get().getPlayer(client)->setMousePosition(mousePosition);
}
