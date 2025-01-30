#include "Protocol.hpp"
#include "GameConfig.hpp"
#include "Network.hpp"
#include "OpCodes.hpp"

void Protocol::injector(char* buffer, size_t length, SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void Protocol::handle_message(Network& network,
                              std::shared_ptr<asio::ip::tcp::socket> client,
                              SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::JOIN: {
        smartBuffer.reset();
        smartBuffer << static_cast<uint8_t>(OpCodes::WORLD)
                    << GameConfig::WORLD_WIDTH << GameConfig::WORLD_HEIGHT;
        network.send_to_client(client, smartBuffer);
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}
