#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <memory>
#include "geometry/Vector2.hpp"

class Player {
  public:
    Player(const uint32_t                                id,
           const std::shared_ptr<asio::ip::tcp::socket>& client,
           const std::vector<double>                     color,
           const std::vector<double>                     cellColor);

    uint32_t                               getId() const;
    std::shared_ptr<asio::ip::tcp::socket> getClient() const;
    Vector2                                getViewport() const;
    Vector2                                getMousePosition() const;
    std::vector<double>                    getColor() const;
    std::vector<double>                    getCellColor() const;
    std::string                            getNickname() const;
    double                                 getScore() const;
    double                                 getTotalMass() const;
    double                                 getCellCount() const;

    const void setViewport(const Vector2& newViewport);
    const void setMousePosition(const Vector2& newMousePosition);
    const void setNickname(const std::string& newNickname);
    const void setScore(const double newScore);
    const void setTotalMass(const double newTotalMass);
    const void setCellCount(const double newCellCount);

  private:
    uint32_t                               id;
    std::shared_ptr<asio::ip::tcp::socket> client;
    Vector2                                viewport;
    Vector2                                mousePosition;
    std::vector<double>                    color;
    std::vector<double>                    cellColor;
    std::string                            nickname;
    double                                 score;
    double                                 totalMass;
    double                                 cellCount;
};
