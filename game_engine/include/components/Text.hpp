/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Text.hpp
*/

#pragma once

#include <string>
#include "Components.hpp"

class Text : public Component {
  public:
    Text(const std::string& text = "", const std::string& fontFile = "",
         unsigned int characterSize = 30);
    ~Text();

    std::string getString() const;
    sf::Font& getFont();
    unsigned int getCharacterSize() const;
    unsigned int getInitCharacterSize() const;
    bool getIsLoaded() const;
    std::string getFontFile() const;
    sf::Text& getText();
    void setIsLoaded(bool isLoaded);
    void setString(const std::string& text);
    void setCharacterSize(unsigned int characterSize);
    void setFontFile(std::string font);
    void display() const override;

  private:
    std::string _initText;
    unsigned int _initSize;
    std::string _fontFile;
    unsigned int _charSize;
    sf::Text _text;
    sf::Font _font;
    bool _isLoad = false;
};
