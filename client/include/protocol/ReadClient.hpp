#pragma once

#include <SmartBuffer.hpp>

class ReadClient {
  public:
    static const void readPingPong(SmartBuffer& smartBuffer);
    static const void readCreateWorld(SmartBuffer& smartBuffer);
    static const void readCreatePlayer(SmartBuffer& smartBuffer);
    static const void readUpdateGameState(SmartBuffer& smartBuffer);
    static const void readSpawnPellets(SmartBuffer& smartBuffer);
    static const void readUpdatePlayer(SmartBuffer& smartBuffer);
    static const void readDeleteEntity(SmartBuffer& smartBuffer);
    static const void readDeletePlayer(SmartBuffer& smartBuffer);
};
