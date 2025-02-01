#include "protocol/ProtocolClient.hpp"
#include <iostream>
#include "components/Cell.hpp"
#include "components/ColorClient.hpp"
#include "components/Viewport.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "protocol/OpCodes.hpp"

ProtocolClient& ProtocolClient::get() {
    static ProtocolClient instance;
    return instance;
}

void ProtocolClient::injector(char* buffer, size_t length,
                              SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void ProtocolClient::handleMessage(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::WORLD: {
        uint16_t size;
        smartBuffer >> size;

        if (ConfigClient::Client::DEV_MODE)
            std::cout << "World size received: " << size << std::endl;

        EntityManager::get().createWorld(size);
        break;
    }
    case OpCodes::GAME_STATE: {
        size_t bufferSize = smartBuffer.getSize() - sizeof(uint8_t);
        size_t cellCount = bufferSize / (sizeof(uint32_t) * 2 + sizeof(double) * 3);

        for (size_t i = 0; i < cellCount; i++) {
            CellData cell;
            smartBuffer >> cell.id >> cell.x >> cell.y >>
                cell.radius >> cell.color;

            if (ConfigClient::Client::DEV_MODE)
                std::cout << "Cell received: " << cell.id << " " << cell.x << " " << cell.y << " "
                          << cell.radius << " " << cell.color << std::endl;

            if (EntityManager::get().entities.find(cell.id) ==
                EntityManager::get().entities.end()) {
                EntityManager::get().createCell(
                    cell.id, cell.x, cell.y, cell.radius,
                    ColorClient::intToVec(cell.color));
            } else {
                EntityManager::get().updateCellPosition(cell.id, cell.x,
                                                        cell.y);
            }
        }

        break;
    }
    case OpCodes::VIEWPORT: {
        double x;
        double y;
        smartBuffer >> x >> y;

        if (ConfigClient::Client::DEV_MODE)
            std::cout << "Viewport updated: " << x << " " << y << std::endl;

        Viewport::get().setViewport(x, y);
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
