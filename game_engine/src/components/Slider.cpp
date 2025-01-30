/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Slider.cpp
**
** The Slider class represents a UI slider for continuous values. It allows the
** user to interactively select a value within a given range by sliding a thumb
** along a track. The class handles the graphical elements of the slider, as
*well
** as the user interaction through mouse input.
*/

#include "components/Slider.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Constructor for the Slider component.
 *
 * Initializes the Slider component with the specified minimum, maximum values
 * and the initial position and size on the screen.
 *
 * @param current The current value of the slider.
 * @param minValue The minimum value that the slider can represent.
 * @param maxValue The maximum value that the slider can represent.
 * @param size The size of the slider (width, height).
 */
Slider::Slider(float current, std::pair<double, double> lenght, std::pair<double, double> size)
    : _minValue(lenght.first), _maxValue(lenght.second), _size(size), _currentValue(current) {}

/**
 * @brief Destructor for the Slider component.
 */
Slider::~Slider() {}

/**
 * @brief Get the size of the Slider component.
 *
 * This function retrieves the size of the slider as a pair of doubles.
 *
 * @return A pair of doubles representing the size of the slider (width,
 * height).
 */
std::pair<double, double> Slider::getSize() const {
    return this->_size;
}

/**
 * @brief Set the size of the Slider component.
 *
 * This function sets the size of the slider as a pair of doubles.
 *
 * @param size A pair of doubles representing the new size of the slider (width,
 * height).
 */
void Slider::setSize(std::pair<double, double> size) {
    this->_size = size;
}

/**
 * @brief Display the Slider component information.
 *
 * This function displays a message indicating that the Slider component is
 * being displayed.
 */
sf::RectangleShape& Slider::getBarShape() {
    return this->_barShape;
}

/**
 * @brief Set the shape of the Slider component.
 *
 * This function sets the sf::RectangleShape of the slider.
 *
 * @param shape An sf::RectangleShape object representing the slider.
 */
void Slider::setBarShape(const sf::RectangleShape& barShape) {
    this->_barShape = barShape;
}

/**
 * @brief Display the Slider component information.
 *
 * This function displays a message indicating that the Slider component is
 * being displayed.
 */
sf::CircleShape& Slider::getCursorShape() {
    return this->_cursorShape;
}

/**
 * @brief Set the shape of the Slider cursor component.
 *
 * This function sets the sf::CircleShape of the slider.
 *
 * @param shape An sf::CircleShape object representing the cursor.
 */
void Slider::setCursorShape(const sf::CircleShape& cursorShape) {
    this->_cursorShape = cursorShape;
}

/**
 * @brief Get whether the Slider component is loaded.
 *
 * This function checks if the Slider component has been initialized.
 *
 * @return True if the Slider is loaded, false otherwise.
 */
bool Slider::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Set whether the Slider component is loaded.
 *
 * This function sets the loaded state of the Slider component.
 */
void Slider::setIsLoaded() {
    this->_isLoad = !this->_isLoad;
}

/**
 * @brief Set the current value of the Slider.
 *
 * This function allows setting the current value of the slider, typically used
 * for initializing or resetting the slider.
 *
 * @param value The new value of the slider.
 */
void Slider::setValue(float value) {
    // std::cout << "current value ->" << _currentValue << std::endl;
    this->_currentValue = value;
}

/**
 * @brief Get the current value of the Slider.
 *
 * This function retrieves the current value selected by the user.
 *
 * @return A float representing the current value of the slider.
 */
int Slider::getValue() const {
    return static_cast<int>(round(_currentValue));
}

/**
 * @brief Set the minimum value of the Slider.
 *
 * This function sets the minimum value of the slider. The minimum value is the
 * left most position of the slider.
 *
 * @param minValue The new minimum value of the slider.
 */
void Slider::setMinValue(float minValue) {
    _minValue = minValue;
}

/**
 * @brief Get the minimum value of the Slider.
 *
 * This function gets the minimum value of the slider. The minimum value is the
 * left most position of the slider.
 *
 * @return The minimum value of the slider.
 */
float Slider::getMinValue() const {
    return this->_minValue;
}

/**
 * @brief Set the maximum value of the Slider.
 *
 * This function sets the maximum value of the slider. The maximum value is the
 * right most position of the slider.
 *
 * @param maxValue The new maximum value of the slider.
 */
void Slider::setMaxValue(float maxValue) {
    _maxValue = maxValue;
}

/**
 * @brief Get the maximum value of the Slider.
 *
 * This function gets the maximum value of the slider. The maximum value is the
 * right most position of the slider.
 *
 * @return The maximum value of the slider.
 */
float Slider::getMaxValue() const {
    return this->_maxValue;
}

/**
 * @brief Set function for get callback.
 *
 * This function sets the get callback state of the Slider component.
 * @param callback An std::function object representing the function to
 * callback.
 */
void Slider::setCallback(std::function<void(float)> callback) {
    _callback = callback;
}

/**
 * @brief Execute function set callback.
 *
 * This function call the function set in callback of the Slider component.
 */
void Slider::executeCallback(int arg) {
    if (_callback) {
        return _callback(arg);
    }
}

/**
 * @brief Display the Slider component information.
 *
 * This function displays a message indicating that the Slider component is
 * being displayed.
 */
void Slider::display() const {
    std::cout << "Slider component displayed!" << std::endl;
}