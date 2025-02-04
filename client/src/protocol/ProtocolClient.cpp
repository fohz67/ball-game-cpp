#include "protocol/ProtocolClient.hpp"
#include <iostream>
#include "components/ColorClient.hpp"
#include "components/Viewport.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/DataInterfaces.hpp"
#include "protocol/HandlersClient.hpp"
#include "protocol/OpCodes.hpp"

ProtocolClient& ProtocolClient::get() {
    static ProtocolClient instance;
    return instance;
}

void ProtocolClient::handleMessage(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {

    case OpCodes::PINGPONG: {
        HandlersClient::handlePing(smartBuffer);
        break;
    }

    case OpCodes::WORLD: {
        HandlersClient::handleWorld(smartBuffer);
        break;
    }

    case OpCodes::PLAYER: {
        HandlersClient::handlePlayer(smartBuffer);
        break;
    }

    case OpCodes::CELL: {
        HandlersClient::handleCell(smartBuffer);
        break;
    }

    case OpCodes::PELLET: {
        HandlersClient::handlePellet(smartBuffer);
        break;
    }

    case OpCodes::VIEWPORT: {
        HandlersClient::handleViewport(smartBuffer);
        break;
    }

    case OpCodes::ENTITY_REMOVED: {
        HandlersClient::handleEntityRemoved(smartBuffer);
        break;
    }

    case OpCodes::PLAYER_DELETED: {
        HandlersClient::handlePlayerDeleted(smartBuffer);
        break;
    }

    case OpCodes::ME: {
        HandlersClient::handleMe(smartBuffer);
        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;

        break;
    }
}

void ProtocolClient::sendPing() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PINGPONG;

    auto     now = std::chrono::high_resolution_clock::now();
    uint64_t timestamp =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    smartBuffer << timestamp;

    NetworkClient::get().send(smartBuffer);
}

void ProtocolClient::sendJoin(const std::string nickname) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::JOIN << nickname;

    NetworkClient::get().send(smartBuffer);
}

void ProtocolClient::sendMousePosition(sf::RenderWindow& window, sf::Vector2i& lastMousePos) {
    sf::Vector2i mousePos   = sf::Mouse::getPosition(window);
    sf::Vector2u windowSize = window.getSize();

    std::pair<double, double> normMousePos(((double)mousePos.x / windowSize.x) * 2.0f - 1.0f,
                                           ((double)mousePos.y / windowSize.y) * 2.0f - 1.0f);

    if (mousePos != lastMousePos) {
        lastMousePos = mousePos;

        SmartBuffer smartBuffer;
        smartBuffer << OpCodes::MOUSE_POSITION << normMousePos.first << normMousePos.second;

        NetworkClient::get().send(smartBuffer);
    }
}

void ProtocolClient::sendKeyPressed(std::string keyName) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::KEY_PRESSED << keyName;

    NetworkClient::get().send(smartBuffer);
}
