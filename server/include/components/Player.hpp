#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>
#include "components/MousePosition.hpp"
#include "components/Viewport.hpp"

class Player {
  public:
    Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client);

    uint32_t getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;
    Viewport getViewport() const;
    MousePosition getMousePosition() const;

  private:
    uint32_t id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    Viewport viewport;
    MousePosition mousePosition;
};
