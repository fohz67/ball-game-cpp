#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;

    std::pair<double, double> getViewport() const;
    std::pair<double, double> getMousePosition() const;

    void setViewport(std::pair<double, double> viewport);
    void setMousePosition(std::pair<double, double> mousePosition);

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    std::pair<double, double> viewport;
    std::pair<double, double> mousePosition;
};
