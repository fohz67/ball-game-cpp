#pragma once

#include <SmartBuffer.hpp>

class ReadClient {
  public:
    static const void readPing(SmartBuffer& smartBuffer);
    static const void readWorld(SmartBuffer& smartBuffer);
    static const void readPlayer(SmartBuffer& smartBuffer);
    static const void readCell(SmartBuffer& smartBuffer);
    static const void readPellet(SmartBuffer& smartBuffer);
    static const void readViewport(SmartBuffer& smartBuffer);
    static const void readEntityRemoved(SmartBuffer& smartBuffer);
    static const void readPlayerDeleted(SmartBuffer& smartBuffer);
    static const void readMe(SmartBuffer& smartBuffer);
};
