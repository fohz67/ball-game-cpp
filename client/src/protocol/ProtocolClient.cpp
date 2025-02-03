#include "protocol/ProtocolClient.hpp"
#include <iostream>
#include "protocol/DataInterfaces.hpp"
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
        WorldInterface world;
        smartBuffer >> world.size;
        
        EntityManager::get().createWorld(world.size);

        break;
    }

    case OpCodes::PLAYER: {
        return;
        
        PlayerInterface player;
        smartBuffer >> player.id >> player.color >> player.cellColor;

        PlayerManagerClient::get().players.emplace_back(player.id, ColorClient::intToVec(player.color),
                             ColorClient::intToVec(player.cellColor));

        break;
    }

    case OpCodes::CELL: {
        uint32_t actualOwnrId = 0;
        std::vector<double> actualColor = {-1};

        for (size_t i = 0; i < NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(CellInterface)); i++) {
            CellInterface cell;
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
        for (size_t i = 0; i < NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(PelletInterface)); i++) {
            PelletInterface cell;
            smartBuffer >> cell.id >> cell.x >> cell.y >> cell.radius >>
                cell.color;

            EntityManager::get().createCell(cell.id, cell.x, cell.y,
                                            cell.radius,
                                            ColorClient::intToVec(cell.color));
        }

        break;
    }

    case OpCodes::VIEWPORT: {
        ViewportInterface viewport;
        smartBuffer >> viewport.x >> viewport.y;

        Viewport::get().setViewport({viewport.x, viewport.y});

        break;
    }

    case OpCodes::ENTITY_REMOVED: {
        EntityInterface entity;
        smartBuffer >> entity.type;

        for (size_t i = 0; i < NetworkClient::get().getCutPacketSize(smartBuffer, sizeof(EntityInterface)); i++) {            
            smartBuffer >> entity.id;
            std::cout << "Entity removed with id: " << entity.id << std::endl;

            if (entity.type) {
                EntityManager::get().removeEntity(entity.id);
            } else {
                PlayerManagerClient::get().removePlayer(entity.id);
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
