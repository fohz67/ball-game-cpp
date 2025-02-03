#include "protocol/Protocol.hpp"
#include <iostream>
#include "components/ColorServer.hpp"
#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/OpCodes.hpp"

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
        smartBuffer.reset();
        smartBuffer << OpCodes::WORLD << Config::Gameplay::World::SIZE;

        Network::get().sendToClient(client, smartBuffer);
        sendCells(CellType::PELLET);

        break;
    }

    case OpCodes::MOUSE_POSITION: {
        double mouseX;
        double mouseY;
        smartBuffer >> mouseX >> mouseY;

        PlayerManager::get().getPlayerByClient(client)->setMousePosition(
            Vector2(mouseX, mouseY));

        break;
    }

    case OpCodes::KEY_PRESSED: {
        std::string keyName;
        smartBuffer >> keyName;

        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void Protocol::sendCells(CellType type) {
    const size_t cellSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;

    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::CELL;

    for (const auto& cell : CellManager::get().getAllCells()) {
        if (cell.getType() != type) {
            continue;
        }

        if (smartBuffer.getSize() + cellSize >= Config::Network::MAX_SIZE + 1) {
            if (smartBuffer.getSize() >= Config::Network::MAX_SIZE) {
                std::cout << "Packet size exceeds maximum size" << std::endl;
            }

            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::CELL;
        }

        Vector2 pos = cell.getPosition();

        smartBuffer << cell.getId() << pos.x << pos.y << cell.getRadius()
                    << ColorServer::vecToInt(cell.getColor());
    }    

    if (smartBuffer.getSize() > sizeof(uint8_t)) {
        Network::get().sendToAll(smartBuffer);
    }
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;

    for (const auto& player : PlayerManager::get().getAllPlayers()) {
        Vector2 viewport = player.getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::VIEWPORT << viewport.x << viewport.y;

        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}

void Protocol::sendEntityRemoved(const std::vector<uint32_t>& deletedIds) {
    const size_t entitySize = sizeof(uint32_t);

    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::ENTITY_REMOVED;

    for (uint32_t cellId : deletedIds) {
        if (smartBuffer.getSize() + entitySize >= Config::Network::MAX_SIZE) {
            if (smartBuffer.getSize() >= Config::Network::MAX_SIZE) {
                std::cout << "Packet size exceeds maximum size" << std::endl;
            }

            Network::get().sendToAll(smartBuffer);

            smartBuffer.reset();
            smartBuffer << OpCodes::ENTITY_REMOVED;
        }

        smartBuffer << cellId;
    }

    Network::get().sendToAll(smartBuffer);
}
