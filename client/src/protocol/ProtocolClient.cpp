#include "protocol/ProtocolClient.hpp"

#include <iostream>

#include "protocol/OpCodes.hpp"
#include "protocol/ReadClient.hpp"

ProtocolClient& ProtocolClient::get()
{
    static ProtocolClient instance;
    return instance;
}

const void ProtocolClient::handleMessage(SmartBuffer& smartBuffer)
{
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode))
    {
        case OpCodes::PINGPONG:
        {
            ReadClient::readPingPong(smartBuffer);
            break;
        }

        case OpCodes::CREATE_WORLD:
        {
            ReadClient::readCreateWorld(smartBuffer);
            break;
        }

        case OpCodes::CREATE_PLAYER:
        {
            ReadClient::readCreatePlayer(smartBuffer);
            break;
        }

        case OpCodes::UPDATE_PLAYER:
        {
            ReadClient::readUpdatePlayer(smartBuffer);
            break;
        }

        case OpCodes::DELETE_PLAYER:
        {
            ReadClient::readDeletePlayer(smartBuffer);
            break;
        }

        case OpCodes::SPAWN_PELLETS:
        {
            ReadClient::readSpawnPellets(smartBuffer);
            break;
        }

        case OpCodes::UPDATE_GAME_STATE:
        {
            ReadClient::readUpdateGameState(smartBuffer);
            break;
        }

        case OpCodes::DELETE_ENTITY:
        {
            ReadClient::readDeleteEntity(smartBuffer);
            break;
        }

        default:
            std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;

            break;
    }
}
