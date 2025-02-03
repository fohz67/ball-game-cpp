#include "protocol/ProtocolClient.hpp"
#include <iostream>
#include "components/CellData.hpp"
#include "components/ColorClient.hpp"
#include "components/Viewport.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/OpCodes.hpp"

ProtocolClient& ProtocolClient::get() {
    static ProtocolClient instance;
    return instance;
}

void ProtocolClient::handleMessage(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {

    case OpCodes::WORLD: {
        uint16_t size;
        smartBuffer >> size;

        EntityManager::get().createWorld(size);

        break;
    }

    case OpCodes::CELL: {
        uint32_t actualOwnrId = 0;
        std::vector<double> actualColor = {-1};

        const size_t cellSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;
        const size_t smartBufferSize = smartBuffer.getSize();
        const size_t cellsNb = (smartBufferSize - sizeof(uint8_t)) / cellSize;

        for (size_t i = 0; i < cellsNb; i++) {
            CellData cell;
            smartBuffer >> cell.id >> cell.ownerId >> cell.x >> cell.y >>
                cell.radius;

            if (actualOwnrId != cell.ownerId && actualOwnrId) {
                actualOwnrId = 0;
            }
            if (actualOwnrId) {
                actualOwnrId = cell.ownerId;
                actualColor = PlayerManagerClient::get()
                                  .getPlayer(cell.ownerId)
                                  ->getColor();
            }

            if (EntityManager::get().entities.find(cell.id) ==
                EntityManager::get().entities.end()) {
                EntityManager::get().createCell(cell.id, cell.x, cell.y,
                                                cell.radius, actualColor);
            } else {
                EntityManager::get().updateCell(cell.id, cell.x, cell.y,
                                                cell.radius, actualColor);
            }
        }

        break;
    }

    case OpCodes::PELLET: {
        const size_t pelletSize = sizeof(uint32_t) * 2 + sizeof(double) * 3;
        const size_t smartBufferSize = smartBuffer.getSize();
        const size_t cellsNb = (smartBufferSize - sizeof(uint8_t)) / pelletSize;

        for (size_t i = 0; i < cellsNb; i++) {
            PelletData cell;
            smartBuffer >> cell.id >> cell.x >> cell.y >> cell.radius >>
                cell.color;

            EntityManager::get().createCell(cell.id, cell.x, cell.y,
                                            cell.radius,
                                            ColorClient::intToVec(cell.color));
        }

        break;
    }

    case OpCodes::VIEWPORT: {
        double x;
        double y;
        smartBuffer >> x >> y;

        Viewport::get().setViewport({x, y});

        break;
    }

    case OpCodes::ENTITY_REMOVED: {
        const size_t entitySize = sizeof(uint8_t) + sizeof(uint32_t);
        const size_t smartBufferSize = smartBuffer.getSize();
        const size_t entitiesNb =
            (smartBufferSize - sizeof(uint8_t)) / entitySize;

        for (size_t i = 0; i < entitiesNb; i++) {
            uint8_t entityType;
            uint32_t entityId;
            smartBuffer >> entityType >> entityId;

            if (entityType) {
                EntityManager::get().removeEntity(entityId);
            } else {
                PlayerManagerClient::get().removePlayer(entityId);
            }
        }

        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;

        break;
    }
}

void ProtocolClient::sendJoin() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::JOIN;

    NetworkClient::get().send(smartBuffer);
}

void ProtocolClient::sendMousePosition(sf::RenderWindow& window,
                                       sf::Vector2i& lastMousePos) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2u windowSize = window.getSize();

    double normX = ((double)mousePos.x / windowSize.x) * 2.0f - 1.0f;
    double normY = ((double)mousePos.y / windowSize.y) * 2.0f - 1.0f;

    if (mousePos != lastMousePos) {
        lastMousePos = mousePos;

        SmartBuffer smartBuffer;
        smartBuffer << OpCodes::MOUSE_POSITION << normX << normY;

        NetworkClient::get().send(smartBuffer);
    }
}

void ProtocolClient::sendKeyPressed(std::string keyName) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::KEY_PRESSED << keyName;

    NetworkClient::get().send(smartBuffer);
}
