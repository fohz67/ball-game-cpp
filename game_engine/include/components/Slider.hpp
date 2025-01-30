/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Slider.hpp
**
** The Slider class represents a UI slider component that allows users to select
** a value from a range by dragging a thumb along a track.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <utility>
#include "Components.hpp"

class Slider : public Component {
  public:
    Slider(float current, std::pair<double, double> lenght, std::pair<double, double> size);
    ~Slider();

    std::pair<double, double> getSize() const;
    void setSize(std::pair<double, double> size);
    sf::RectangleShape& getBarShape();
    void setBarShape(const sf::RectangleShape&);
    sf::CircleShape& getCursorShape();
    void setCursorShape(const sf::CircleShape&);
    int getValue() const;
    void setValue(float);

    void setMinValue(float minValue);
    float getMinValue() const;

    void setMaxValue(float maxValue);
    float getMaxValue() const;

    bool getIsLoaded() const;
    void setIsLoaded();

    void setCallback(std::function<void(float)>);
    void executeCallback(int arg);
    
    void display() const;

  private:
    std::pair<double, double> _size;
    float _minValue;
    float _maxValue;
    float _currentValue;
    bool _isLoad = false;
    sf::RectangleShape _barShape;
    sf::CircleShape _cursorShape;
    std::function<void(float)> _callback;
};
