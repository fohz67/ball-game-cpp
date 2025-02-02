#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>
#include "geometry/Vector2.hpp"

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;

    Vector2 getViewport() const;
    Vector2 getMousePosition() const;

    void setViewport(const Vector2& newViewport);
    void setMousePosition(const Vector2& newMousePosition);

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    Vector2 viewport;
    Vector2 mousePosition;
};
