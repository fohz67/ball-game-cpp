#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include "components/Components.hpp"
#include "components/Point.hpp"

class Position : public Component {
  public:
    // Constants
    static inline std::vector<Point> DEFAULT_POSITIONS = {{0.0f, 0.0f}};

    // Constructor / Destructor
    Position(const std::vector<Point>& positions = DEFAULT_POSITIONS);
    ~Position() = default;

    // Getters
    std::vector<Point> getPositions() const;
    double getPositionX(const uint32_t id) const;
    double getPositionY(const uint32_t id) const;

    // Setters
    void setPositionX(const uint32_t id, const double x);
    void setPositionY(const uint32_t id, const double y);

    // Methods
    void addPosition(const double x, const double y);
    void removePosition(const uint32_t id);
    void display() const override;

  private:
    // Attributes
    std::vector<Point> positions;
};
