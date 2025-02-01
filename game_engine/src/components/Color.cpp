#include "components/Color.hpp"
#include <iostream>

Color::Color(const std::vector<double>& color) : _initColor(color) {}

std::vector<double> Color::getColor() const {
    return this->_initColor;
}

void Color::setColor(const std::vector<double>& color) {
    this->_initColor = color;
}

void Color::display() const {
    std::cout << "Color component displayed!" << std::endl;
}
