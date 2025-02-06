#include "protocol/ProtocolClient.hpp"
#include <iostream>
#include "protocol/OpCodes.hpp"
#include "protocol/ReadClient.hpp"

ProtocolClient& ProtocolClient::get() {
    static ProtocolClient instance;
    return instance;
}

const void ProtocolClient::handleMessage(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {

    case OpCodes::PINGPONG: {
        ReadClient::readPing(smartBuffer);
        break;
    }

    case OpCodes::WORLD: {
        ReadClient::readWorld(smartBuffer);
        break;
    }

    case OpCodes::PLAYER: {
        ReadClient::readPlayer(smartBuffer);
        break;
    }

    case OpCodes::CELL: {
        ReadClient::readCell(smartBuffer);
        break;
    }

    case OpCodes::PELLET: {
        ReadClient::readPellet(smartBuffer);
        break;
    }

    case OpCodes::VIEWPORT: {
        ReadClient::readViewport(smartBuffer);
        break;
    }

    case OpCodes::ENTITY_REMOVED: {
        ReadClient::readEntityRemoved(smartBuffer);
        break;
    }

    case OpCodes::PLAYER_DELETED: {
        ReadClient::readPlayerDeleted(smartBuffer);
        break;
    }

    case OpCodes::ME: {
        ReadClient::readMe(smartBuffer);
        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;

        break;
    }
}
