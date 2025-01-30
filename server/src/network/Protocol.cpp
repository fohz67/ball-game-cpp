#include "network/Protocol.hpp"
#include "Config.hpp"
#include "comps/cell/CellManager.hpp"
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
        sendWorld();
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
    std::cout << "Mouse position: " << x << ", " << y << "PlayerID: " << PlayerManager::get().getPlayerByClient(client)->getId() << std::endl;
}

void Protocol::sendWorld() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::WORLD) << Config::World::WIDTH
                << Config::World::HEIGHT;
    Network::get().sendToAll(smartBuffer);
}

void Protocol::sendGameState() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::GAME_STATE);
    const auto& allCells = CellManager::get().getAllCells();
    std::cout << "Sending " << allCells.size() << " cells" << std::endl;
    for (const auto& cell : allCells) {
        smartBuffer << static_cast<uint32_t>(cell.getOwnerId());
        smartBuffer << static_cast<float>(cell.getX());
        smartBuffer << static_cast<float>(cell.getY());
        smartBuffer << static_cast<float>(cell.getRadius());
    }
    Network::get().sendToAll(smartBuffer);
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;
    const auto& allPlayers = PlayerManager::get().getAllPlayers();
    for (const auto& player : allPlayers) {
        smartBuffer.reset();
        smartBuffer << static_cast<uint8_t>(OpCodes::VIEWPORT);
        smartBuffer << static_cast<uint32_t>(player.getId());
        smartBuffer << player.getViewport().first;
        smartBuffer << player.getViewport().second;
        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}
