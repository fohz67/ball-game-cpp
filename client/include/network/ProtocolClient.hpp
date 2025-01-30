#pragma once

#include <SmartBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class ProtocolClient {
  public:
    ProtocolClient(const ProtocolClient&) = delete;
    ProtocolClient& operator=(const ProtocolClient&) = delete;
    static ProtocolClient& get();
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handleMessage(SmartBuffer& smartBuffer);
    static void sendMousePosition(sf::RenderWindow& window, sf::Vector2i& lastMousePos);

  private:
    ProtocolClient() = default;
    ~ProtocolClient() = default;
    static void handleWorld(SmartBuffer& smartBuffer);
    static void handleGameState(SmartBuffer& smartBuffer);
};
