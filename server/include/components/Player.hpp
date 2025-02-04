#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>
#include "geometry/Vector2.hpp"

class Player {
  public:
    Player(uint32_t                               id,
           std::shared_ptr<asio::ip::tcp::socket> client,
           std::vector<double>                    color,
           std::vector<double>                    cellColor);

    uint32_t                               getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;
    Vector2                                getViewport() const;
    Vector2                                getMousePosition() const;
    std::vector<double>                    getColor() const;
    std::vector<double>                    getCellColor() const;
    std::string                            getNickname() const;

    void setViewport(const Vector2& newViewport);
    void setMousePosition(const Vector2& newMousePosition);
    void setNickname(const std::string& newNickname);

  private:
    uint32_t                               id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    Vector2                                viewport;
    Vector2                                mousePosition;
    std::vector<double>                    color;
    std::vector<double>                    cellColor;
    std::string                            nickname;
};
