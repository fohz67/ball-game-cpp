#pragma once

#include <asio.hpp>
#include <memory>

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;
    std::pair<float, float> getViewport() const;
    float getViewportX() const;
    float getViewportY() const;
    void setViewport(float x, float y);
    std::pair<float, float> getMousePosition() const;
    float getMouseX() const;
    float getMouseY() const;
    void setMousePosition(float x, float y);

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    float viewportX, viewportY;
    float mouseX, mouseY;
};
