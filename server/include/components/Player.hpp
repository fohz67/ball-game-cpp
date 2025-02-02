#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>
#include "components/Point.hpp"

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;

    Point getViewport() const;
    Point getMousePosition() const;

    void setViewport(Point viewport);
    void setMousePosition(Point mousePosition);

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    Point viewport;
    Point mousePosition;
};
