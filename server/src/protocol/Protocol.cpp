#include "protocol/Protocol.hpp"

#include <iostream>

#include "config/Config.hpp"
#include "engine/Network.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/Read.hpp"
#include "util/ColorConverter.hpp"

Protocol& Protocol::get()
{
    static Protocol instance;
    return instance;
}

const void Protocol::injector(char* buffer, const size_t length, SmartBuffer& smartBuffer)
{
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

const void Protocol::handleMessage(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                   SmartBuffer& smartBuffer)
{
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode))
    {
        case OpCodes::PINGPONG:
        {
            Read::readPingPong(client, smartBuffer);
            break;
        }

        case OpCodes::JOIN_SERVER:
        {
            Read::readJoinServer(client, smartBuffer);
            break;
        }

        case OpCodes::UPDATE_MOUSE_POSITION:
        {
            Read::readUpdateMousePosition(client, smartBuffer);
            break;
        }

        default:
            std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;
            break;
    }
}
