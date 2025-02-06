#include "components/OptionButton.hpp"
#include <iostream>

OptionButton::OptionButton(Point size) : size(size) {}

Point OptionButton::getSize() const {
    return this->size;
}

sf::RectangleShape& OptionButton::getShape() {
    return this->optionbutton;
}

bool OptionButton::isLoaded() const {
    return this->loaded;
}

bool OptionButton::isChecked() const {
    return this->checked;
}

void OptionButton::setSize(const Point val) {
    this->size = val;
}

void OptionButton::setShape(const sf::RectangleShape& val) {
    this->optionbutton = val;
}

void OptionButton::setLoaded() {
    this->loaded = !this->loaded;
}

void OptionButton::setChecked() {
    this->checked = !this->checked;
}

void OptionButton::setCallback(const std::function<void()> val) {
    callback = val;
}

void OptionButton::executeCallback() const {
    if (callback) {
        callback();
    }
}

void OptionButton::display() const {
    std::cout << "OptionButton component displayed!" << std::endl;
}
