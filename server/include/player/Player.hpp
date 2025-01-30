#pragma once

#include <asio.hpp>
#include <memory>

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;
    std::pair<float, float> getViewport() const;
    void setViewport(float x, float y);

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    float viewportX, viewportY;
};
