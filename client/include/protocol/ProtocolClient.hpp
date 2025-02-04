#pragma once

#include <SFML/Graphics.hpp>
#include <SmartBuffer.hpp>
#include <string>

class ProtocolClient {
  public:
    ProtocolClient(const ProtocolClient&) = delete;
    ProtocolClient& operator=(const ProtocolClient&) = delete;

    static ProtocolClient& get();

    void handleMessage(SmartBuffer& smartBuffer);

    void sendJoin(const std::string nickname);
    void sendMousePosition(sf::RenderWindow& window,
                           sf::Vector2i& lastMousePos);
    void sendKeyPressed(std::string keyName);

  private:
    ProtocolClient() = default;
    ~ProtocolClient() = default;

    void handleGameState(SmartBuffer& smartBuffer);
    void handleViewport(SmartBuffer& smartBuffer);
};
