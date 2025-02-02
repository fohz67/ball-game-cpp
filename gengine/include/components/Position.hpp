/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Position.hpp
*/

#pragma once

#include "Components.hpp"

class Position : public Component {
  public:
    // Constants
    static inline std::vector<std::pair<double, double>> DEFAULT_POSITIONS = {
        {0.0f, 0.0f}};

    // Constructor / Destructor
    Position(const std::vector<std::pair<double, double>>& positions =
                 DEFAULT_POSITIONS);
    ~Position() = default;

    // Getters
    std::vector<std::pair<double, double>> getPositions() const;
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
    std::vector<std::pair<double, double>> positions;
};
