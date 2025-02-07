#include "components/Slider.hpp"

#include <cmath>
#include <iostream>

Slider::Slider(const double current, const Point lenght, const Point size)
    : min(lenght.first), max(lenght.second), size(size), current(current)
{
}

Point Slider::getSize() const { return this->size; }

sf::RectangleShape& Slider::getBarShape() { return this->barShape; }

sf::CircleShape& Slider::getCursorShape() { return this->cursorShape; }

bool Slider::isLoaded() const { return this->loaded; }

int Slider::getValue() const { return static_cast<int>(round(current)); }

double Slider::getMinValue() const { return this->min; }

double Slider::getMaxValue() const { return this->max; }

void Slider::setSize(const Point val) { this->size = val; }

void Slider::setBarShape(const sf::RectangleShape& val) { this->barShape = val; }

void Slider::setCursorShape(const sf::CircleShape& val) { this->cursorShape = val; }

void Slider::setLoaded() { this->loaded = !this->loaded; }

void Slider::setValue(const double val) { this->current = val; }

void Slider::setMinValue(const double val) { min = val; }

void Slider::setMaxValue(const double val) { max = val; }

void Slider::setCallback(const std::function<void(double)> val) { callback = val; }

void Slider::executeCallback(const int val)
{
    if (callback)
    {
        return callback(val);
    }
}

void Slider::display() const { std::cout << "Slider component displayed!" << std::endl; }
