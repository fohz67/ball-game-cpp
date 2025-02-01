#include "components/Button.hpp"
#include <iostream>

Button::Button(const std::string text, const std::string fontFile,
               const uint16_t characterSize)
    : baseText(text), fontFile(fontFile), characterSize(characterSize) {}

sf::RectangleShape& Button::getButton() {
    return button;
}

sf::Text& Button::getText() {
    return text;
}

std::string Button::getString() const {
    return baseText;
}

std::string Button::getFontFile() const {
    return fontFile;
}

sf::Font& Button::getFont() {
    return font;
}

uint16_t Button::getCharacterSize() const {
    return characterSize;
}

std::pair<double, double> Button::getSize() const {
    return size;
}

bool Button::isLoaded() const {
    return load;
}

bool Button::isHovered(const sf::Vector2i mousePos) const {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x),
                                             static_cast<float>(mousePos.y));
}

void Button::setString(const std::string textVal) {
    baseText = textVal;
}

void Button::setLoaded(const bool loaded) {
    load = loaded;
}

void Button::setCallback(const std::function<void()> callbackFunc) {
    callback = callbackFunc;
}

void Button::display() const {
    std::cout << "Button component displayed!" << std::endl;
}

void Button::executeCallback() const {
    if (callback) {
        callback();
    }
}
