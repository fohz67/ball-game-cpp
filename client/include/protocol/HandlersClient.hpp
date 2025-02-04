#pragma once

#include <SmartBuffer.hpp>

class HandlersClient {
  public:
    static void handleWorld(SmartBuffer& smartBuffer);
    static void handlePlayer(SmartBuffer& smartBuffer);
    static void handleCell(SmartBuffer& smartBuffer);
    static void handlePellet(SmartBuffer& smartBuffer);
    static void handleViewport(SmartBuffer& smartBuffer);
    static void handleEntityRemoved(SmartBuffer& smartBuffer);
    static void handlePlayerDeleted(SmartBuffer& smartBuffer);
};
