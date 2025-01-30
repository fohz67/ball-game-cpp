#pragma once

#include <SmartBuffer.hpp>
#include <iostream>
#include "comps/world/WorldClient.hpp"

class ProtocolClient {
  public:
    ProtocolClient(const ProtocolClient&) = delete;
    ProtocolClient& operator=(const ProtocolClient&) = delete;
    static ProtocolClient& get();
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handle_message(SmartBuffer& smartBuffer);

  private:
    ProtocolClient() = default;
    ~ProtocolClient() = default;
    static void handleWorld(SmartBuffer& smartBuffer);
    static void handleGameState(SmartBuffer& smartBuffer);
};
