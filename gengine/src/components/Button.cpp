#include "components/Button.hpp"
#include <iostream>

Button::Button(const std::string text, const std::string fontFile,
               const uint16_t characterSize)
    : initText(text), fontFile(fontFile), characterSize(characterSize) {}

sf::RectangleShape& Button::getButton() {
    return button;
}

sf::Text& Button::getText() {
    return text;
}

std::string Button::getString() const {
    return initText;
}

std::string Button::getFontFile() const {
    return fontFile;
}

uint16_t Button::getCharacterSize() const {
    return characterSize;
}

Point Button::getSize() const {
    return size;
}

sf::Font& Button::getFont() {
    return font;
}

bool Button::isLoaded() const {
    return load;
}

void Button::setString(const std::string val) {
    initText = val;
}

void Button::setLoaded(const bool val) {
    load = val;
}

void Button::setCallback(const std::function<void()> val) {
    callback = val;
}

bool Button::isHovered(const sf::Vector2i mousePos) const {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x),
                                             static_cast<float>(mousePos.y));
}

void Button::display() const {
    std::cout << "Button component displayed!" << std::endl;
}

void Button::executeCallback() const {
    if (callback) {
        callback();
    }
}
