#include "network/Protocol.hpp"
#include "cell/CellManager.hpp"
#include "config/Config.hpp"
#include "network/Network.hpp"
#include "network/OpCodes.hpp"
#include "player/PlayerManager.hpp"

Protocol& Protocol::get() {
    static Protocol instance;
    return instance;
}

void Protocol::injector(char* buffer, size_t length, SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void Protocol::handleMessage(std::shared_ptr<asio::ip::tcp::socket> client,
                             SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::JOIN: {
        sendWorld(client);
        break;
    }
    case OpCodes::MOUSE_POSITION: {
        handleMouseMove(client, smartBuffer);
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void Protocol::handleMouseMove(std::shared_ptr<asio::ip::tcp::socket> client,
                               SmartBuffer& smartBuffer) {
    float x, y;
    smartBuffer >> x >> y;
    PlayerManager::get().getPlayerByClient(client)->setMousePosition(x, y);
}

void Protocol::sendWorld(std::shared_ptr<asio::ip::tcp::socket> client) {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::WORLD) << static_cast<int>(Config::GameMode::WORLD_SIZE);
    Network::get().sendToClient(client, smartBuffer);
}

void Protocol::sendGameState() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::GAME_STATE);
    const auto& allCells = CellManager::get().getCells();
    for (const auto& cell : allCells) {
        smartBuffer << static_cast<uint32_t>(cell.getOwnerId())
                    << static_cast<float>(cell.getPosition().x)
                    << static_cast<float>(cell.getPosition().y)
                    << static_cast<float>(cell.getRadius());
    }
    Network::get().sendToAll(smartBuffer);
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;
    const auto& allPlayers = PlayerManager::get().getAllPlayers();
    for (const auto& player : allPlayers) {
        smartBuffer << static_cast<uint8_t>(OpCodes::VIEWPORT)
                    << player.getViewport().first
                    << player.getViewport().second;
        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}
