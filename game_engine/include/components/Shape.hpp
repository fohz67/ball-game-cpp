/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Shape.hpp
*/

#pragma once

#include <string>
#include "Components.hpp"

enum ShapeType { Circle, Rectangle };

class Shape : public Component {
  public:
    Shape(ShapeType type = Rectangle,
          const std::pair<double, double>& size = {0.0, 0.0},
          float radius = 1.0);
    ~Shape();
    void setShape(const sf::RectangleShape& rect);
    void setShape(const sf::CircleShape& circle);
    sf::RectangleShape& getRect();
    sf::CircleShape& getCircle();
    bool getIsLoaded() const;
    void setIsLoaded(bool isLoad);
    float getRadius() const;
    ShapeType getShapeType() const;
    std::pair<double, double> getSize() const;
    void setSize(const std::pair<double, double>& size);
    void display() const override;

  private:
    std::pair<double, double> _size;
    float _radius;
    sf::RectangleShape _rect;
    ShapeType _type;
    sf::CircleShape _circle;
    bool _isLoad = false;
};
