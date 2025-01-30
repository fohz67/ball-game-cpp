#include "network/Protocol.hpp"
#include "comps/cell/CellManager.hpp"
#include "network/Network.hpp"
#include "network/OpCodes.hpp"
#include "player/PlayerManager.hpp"
#include "util/GameConfig.hpp"

Protocol& Protocol::get() {
    static Protocol instance;
    return instance;
}

void Protocol::injector(char* buffer, size_t length, SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void Protocol::handle_message(std::shared_ptr<asio::ip::tcp::socket> client,
                              SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::JOIN: {
        sendWorld();
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void Protocol::sendWorld() {
    SmartBuffer smartBuffer;
    smartBuffer << static_cast<uint8_t>(OpCodes::WORLD)
                << GameConfig::WORLD_WIDTH << GameConfig::WORLD_HEIGHT;
    Network::get().send_to_all(smartBuffer);
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
    Network::get().send_to_all(smartBuffer);
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
        Network::get().send_to_client(player.getClient(), smartBuffer);
    }
}
