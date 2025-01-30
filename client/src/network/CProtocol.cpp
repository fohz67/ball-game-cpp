#include "network/CProtocol.hpp"
#include "game_components/cells/CCellsManager.hpp"
#include "network/OpCodes.hpp"

CProtocol& CProtocol::get() {
    static CProtocol instance;
    return instance;
}

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
        handleWorld(smartBuffer);
        break;
    }
    case OpCodes::GAME_STATE: {
        // handleGameState(smartBuffer);
        break;
    }
    case OpCodes::VIEWPORT: {
        std::cout << "Received VIEWPORT opcode" << std::endl;
        // handleViewport(smartBuffer);
        break;
    }
    default:
        std::cout << "Unknown opcode received: " << static_cast<int>(opcode)
                  << std::endl;
        break;
    }
}

void CProtocol::handleWorld(SmartBuffer& smartBuffer) {
    int width, height;
    smartBuffer >> width >> height;

    CWorld::get().init(width, height);
}

void CProtocol::handleGameState(SmartBuffer& smartBuffer) {
    std::vector<CellData> cells;
    size_t bufferSize = smartBuffer.getSize();
    size_t cellSize = sizeof(uint32_t) + 3 * sizeof(float);
    size_t cellCount = bufferSize / cellSize;

    for (size_t i = 0; i < cellCount; i++) {
        CellData cell;
        smartBuffer >> cell.ownerId >> cell.x >> cell.y >> cell.radius;
        cells.push_back(cell);
    }

    CCellsManager::get().updateCells(cells);
}
