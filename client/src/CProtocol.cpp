#include "CProtocol.hpp"
#include "OpCodes.hpp"

void CProtocol::injector(char* buffer, size_t length,
                         SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void CProtocol::handle_message(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::WORLD: {
        int width, height;
        smartBuffer >> width >> height;
        std::cout << "World size: " << width << "x" << height << std::endl;
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}
