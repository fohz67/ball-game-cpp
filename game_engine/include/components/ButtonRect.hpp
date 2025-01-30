/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Button.hpp
*/

#pragma once

#include <functional>
#include <iostream>
#include <string>
#include "Components.hpp"

class ButtonRect : public Component {
  public:
    ButtonRect(const std::pair<int, int>& sizeRect = {150, 50},
               sf::Color color = sf::Color::Red, bool showOutline = false);
    ~ButtonRect();

    sf::RectangleShape& getButtonRect();

    std::pair<int, int> getSize() const;
    sf::Color getColor();

    void setIsLoaded(bool isLoaded);
    bool getIsLoaded() const;

    bool getShowOutline() const;

    void display() const override;
    bool isHovered(sf::Vector2i mousePos);

    void setCallback(std::function<void()>);
    void executeCallback();

  private:
    sf::RectangleShape _buttonRect;
    std::pair<int, int> _size;
    std::function<void()> _callback;
    bool _isLoad = false;
    sf::Color _color;
    bool _showOutline;
};
