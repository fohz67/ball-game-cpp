#include "components/ButtonRect.hpp"
#include <iostream>

ButtonRect::ButtonRect(const std::pair<uint16_t, uint16_t>& sizeRect, sf::Color color,
                       bool showOutline)
    : size(sizeRect), color(color), showOutline(showOutline) {}

sf::RectangleShape& ButtonRect::getButtonRect() {
    return buttonRect;
}

std::pair<uint16_t, uint16_t> ButtonRect::getSize() const {
    return size;
}

sf::Color ButtonRect::getColor() const {
    return color;
}

bool ButtonRect::isLoaded() const {
    return load;
}

bool ButtonRect::isShowOutline() const {
    return showOutline;
}

bool ButtonRect::isHovered(sf::Vector2i mousePos) const {
    return buttonRect.getGlobalBounds().contains(
        static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void ButtonRect::setLoaded(bool isLoaded) {
    load = isLoaded;
}

void ButtonRect::setCallback(const std::function<void()>& callbackFunc) {
    callback = callbackFunc;
}

void ButtonRect::display() const {
    std::cout << "ButtonRect component displayed!" << std::endl;
}

void ButtonRect::executeCallback() const {
    if (callback) {
        callback();
    }
}