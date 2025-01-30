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

class Button : public Component {
  public:
    Button(std::string text = "", std::string fontFile = "",
           unsigned int characterSize = 30);
    ~Button();

    sf::RectangleShape& getButton();
    sf::Text& getText();

    std::string getString() const;
    void setString(std::string text);

    std::string getFontFile() const;
    sf::Font& getFont();

    unsigned int getCharacterSize() const;

    std::pair<double, double> getSize() const;

    void setIsLoaded(bool isLoaded);
    bool getIsLoaded() const;

    void display() const override;
    bool isHovered(sf::Vector2i mousePos);

    void setCallback(std::function<void()>);
    void executeCallback();

  private:
    sf::RectangleShape _button;
    sf::Text _text;
    std::string _initText;
    std::string _fontFile;
    sf::Font _font;
    unsigned int _charSize;
    std::pair<double, double> _size;
    std::function<void()> _callback;
    bool _isLoad = false;
};
