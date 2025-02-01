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
        smartBuffer << OpCodes::WORLD << Config::GameMode::WORLD_SIZE;

        Network::get().sendToClient(client, smartBuffer);
        break;
    }
    case OpCodes::MOUSE_POSITION: {
        double mouseX, mouseY;
        smartBuffer >> mouseX >> mouseY;

        PlayerManager::get()
            .getPlayerByClient(client)
            ->getMousePosition()
            .updatePosition(mouseX, mouseY);

        break;
    }
    case OpCodes::KEY_PRESSED: {
        std::string keyName;
        smartBuffer >> keyName;

        // @TODO handle key pressed
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void Protocol::sendGameState() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::GAME_STATE;

    for (const auto& cell : CellManager::get().getAllCells()) {
        smartBuffer << cell.getOwnerId() << cell.getId() << cell.getX()
                    << cell.getY() << cell.getRadius()
                    << ColorServer::vecToInt(cell.getColor());
    }

    Network::get().sendToAll(smartBuffer);
}

void Protocol::sendViewport() {
    SmartBuffer smartBuffer;

    for (const auto& player : PlayerManager::get().getAllPlayers()) {
        Viewport viewport = player.getViewport();

        smartBuffer.reset();
        smartBuffer << OpCodes::VIEWPORT << viewport.x << viewport.y;

        Network::get().sendToClient(player.getClient(), smartBuffer);
    }
}
