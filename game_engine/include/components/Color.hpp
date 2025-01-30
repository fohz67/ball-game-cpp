/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Color.hpp
*/

#pragma once

#include <vector>
#include "Components.hpp"

class Color : public Component {
  public:
    Color(const std::vector<double>& color = {});
    ~Color();
    std::vector<double> getColor() const;
    void setColor(const std::vector<double>& color);
    void display() const override;

  private:
    std::vector<double> _initColor;
};
