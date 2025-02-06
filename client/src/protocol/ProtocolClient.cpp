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

    case OpCodes::WORLD_CREATED: {
        ReadClient::readWorld(smartBuffer);
        break;
    }

    case OpCodes::NEW_PLAYER: {
        ReadClient::readPlayer(smartBuffer);
        break;
    }

    case OpCodes::UPDATE_CELL: {
        ReadClient::readCell(smartBuffer);
        break;
    }

    case OpCodes::CREATE_PELLETS: {
        ReadClient::readPellet(smartBuffer);
        break;
    }

    case OpCodes::UPDATE_VIEWPORT: {
        ReadClient::readViewport(smartBuffer);
        break;
    }

    case OpCodes::DELETE_ENTITY: {
        ReadClient::readEntityRemoved(smartBuffer);
        break;
    }

    case OpCodes::DELETE_PLAYER: {
        ReadClient::readPlayerDeleted(smartBuffer);
        break;
    }

    case OpCodes::UPDATE_SELF_DATA: {
        ReadClient::readMe(smartBuffer);
        break;
    }

    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;

        break;
    }
}
