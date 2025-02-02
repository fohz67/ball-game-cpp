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
#include "Components.hpp"

class Slider : public Component {
  public:
    // Constants
    Slider(const double current, const std::pair<double, double> lenght,
           const std::pair<double, double> size);
    ~Slider() = default;

    // Getters
    std::pair<double, double> getSize() const;
    sf::RectangleShape& getBarShape();
    sf::CircleShape& getCursorShape();
    int getValue() const;
    double getMinValue() const;
    double getMaxValue() const;
    bool isLoaded() const;

    // Setters
    void setSize(const std::pair<double, double> val);
    void setBarShape(const sf::RectangleShape& val);
    void setCursorShape(const sf::CircleShape& val);
    void setValue(const double var);
    void setMinValue(const double minValue);
    void setMaxValue(const double maxValue);
    void setLoaded();
    void setCallback(const std::function<void(double)> val);

    // Methods
    void executeCallback(const int arg);
    void display() const override;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    sf::RectangleShape barShape;
    sf::CircleShape cursorShape;
    std::pair<double, double> size;
    double min;
    double max;
    double current;
    bool loaded = DEFAULT_LOADED;
    std::function<void(double)> callback;
};
