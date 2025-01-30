/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** OptionButton.hpp
*/

#pragma once

#include <functional>
#include <string>
#include "Components.hpp"

class OptionButton : public Component {
  public:
    OptionButton(std::pair<double, double> size = {0.0, 0.0});
    ~OptionButton();
    std::pair<double, double> getSize() const;
    void setSize(std::pair<double, double> size);
    sf::RectangleShape& getShape();
    void setShape(const sf::RectangleShape&);
    bool getIsLoaded() const;
    void setIsLoaded();
    bool getChecked() const;
    void setChecked();
    void setCallback(std::function<void()>);
    void executeCallback();
    void display() const override;

  private:
    std::pair<double, double> _size;
    enum Shape { Circle, Rectangle };
    sf::RectangleShape _optionbutton;
    bool _isLoad = false;
    bool _isChecked = false;
    std::function<void()> _callback;
};
