#include "network/ProtocolClient.hpp"
#include "ConfigClient.hpp"
#include "comps/cell/CellManagerClient.hpp"
#include "entity/EntityManager.hpp"
#include "network/OpCodes.hpp"

ProtocolClient& ProtocolClient::get() {
    static ProtocolClient instance;
    return instance;
}

void ProtocolClient::injector(char* buffer, size_t length,
                              SmartBuffer& smartBuffer) {
    smartBuffer.reset();
    smartBuffer.inject(reinterpret_cast<uint8_t*>(buffer), length);
}

void ProtocolClient::handle_message(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;

    switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::WORLD: {
        handleWorld(smartBuffer);
        break;
    }
    case OpCodes::GAME_STATE: {
        handleGameState(smartBuffer);
        break;
    }
    case OpCodes::VIEWPORT: {
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void ProtocolClient::handleWorld(SmartBuffer& smartBuffer) {
    int width, height;
    smartBuffer >> width >> height;
    EntityManager::get().createWorld();
}

void ProtocolClient::handleGameState(SmartBuffer& smartBuffer) {
    unsigned long safer = ConfigClient::Cell::SAFER;
    size_t bufferSize = smartBuffer.getSize() - sizeof(uint8_t);
    size_t cellSize = sizeof(uint32_t) + 3 * sizeof(float);
    size_t cellCount = bufferSize / cellSize;

    for (size_t i = 0; i < cellCount; i++) {
        CellData cell;
        smartBuffer >> cell.ownerId >> cell.x >> cell.y >> cell.radius;
        EntityManager::get().createCell(cell.ownerId + safer, cell.x, cell.y,
                                        cell.radius,
                                        ConfigClient::Cell::DEFAULT_COLOR);
        safer++;
    }
}
