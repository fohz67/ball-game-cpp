#pragma once

#include <SmartBuffer.hpp>
#include <iostream>
#include "game_components/CWorld.hpp"

class CProtocol {
  public:
    CProtocol(const CProtocol&) = delete;
    CProtocol& operator=(const CProtocol&) = delete;
    static CProtocol& get();
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handle_message(SmartBuffer& smartBuffer);

  private:
    CProtocol() = default;
    ~CProtocol() = default;
    static void handleWorld(SmartBuffer& smartBuffer);
    static void handleGameState(SmartBuffer& smartBuffer);
};
