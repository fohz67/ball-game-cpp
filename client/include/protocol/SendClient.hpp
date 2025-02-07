#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class SendClient
{
   public:
    static const void sendPing();
    static const void sendJoin(const std::string nickname);
    static const void sendMousePosition(const sf::RenderWindow& window, sf::Vector2i& lastMousePos);
};
