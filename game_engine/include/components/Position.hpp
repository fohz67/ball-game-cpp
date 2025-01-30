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
    Position(const std::vector<std::pair<float, float>>& positions = {
                 {0.0f, 0.0f}});
    ~Position();
    std::vector<std::pair<float, float>> getPositions() const;
    float getPositionX(int id) const;
    void setPositionX(int id, float x);
    float getPositionY(int id) const;
    void setPositionY(int id, float y);
    void addPosition(float x, float y);
    void removePosition(int id);
    void display() const override;

  private:
    std::vector<std::pair<float, float>> _positions;
};
