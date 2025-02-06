#include "protocol/SendClient.hpp"
#include <SmartBuffer.hpp>
#include "engine/NetworkClient.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/ProtocolClient.hpp"

const void SendClient::sendPing() {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::PINGPONG;

    const auto     now = std::chrono::high_resolution_clock::now();
    const uint64_t timestamp =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    smartBuffer << timestamp;

    NetworkClient::get().send(smartBuffer);
}

const void SendClient::sendJoin(const std::string nickname) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::JOIN << nickname;

    NetworkClient::get().send(smartBuffer);
}

const void SendClient::sendMousePosition(const sf::RenderWindow& window,
                                         sf::Vector2i&           lastMousePos) {
    const sf::Vector2i mousePos   = sf::Mouse::getPosition(window);
    const sf::Vector2u windowSize = window.getSize();

    std::pair<double, double> normMousePos(((double)mousePos.x / windowSize.x) * 2.0f - 1.0f,
                                           ((double)mousePos.y / windowSize.y) * 2.0f - 1.0f);

    if (mousePos != lastMousePos) {
        lastMousePos = mousePos;

        SmartBuffer smartBuffer;
        smartBuffer << OpCodes::MOUSE_POSITION << normMousePos.first << normMousePos.second;

        NetworkClient::get().send(smartBuffer);
    }
}

const void SendClient::sendKeyPressed(const std::string keyName) {
    SmartBuffer smartBuffer;
    smartBuffer << OpCodes::KEY_PRESSED << keyName;

    NetworkClient::get().send(smartBuffer);
}
