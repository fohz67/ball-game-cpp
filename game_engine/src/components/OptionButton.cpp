/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** OptionButton.cpp
**
** The OptionButton class represents a UI option button with a text label and a
*size.
** It holds a `text` as a string and `size` as a `std::pair<double, double>` for
*the option button's width and height.
** The constructor allows initializing these attributes with default values.
*/

#include "components/OptionButton.hpp"
#include <iostream>

/**
 * @brief Constructor for the OptionButton component.
 *
 * This constructor initializes the OptionButton component with the specified
 * text and size.
 *
 * @param text A string representing the text on the option button.
 * @param size A pair of doubles representing the size of the option button
 * (width, height).
 */
OptionButton::OptionButton(std::pair<double, double> size) : _size(size) {}

/**
 * @brief Destructor for the OptionButton component.
 *
 * This destructor cleans up any resources used by the OptionButton component.
 */
OptionButton::~OptionButton() {}

/**
 * @brief Get the size of the OptionButton component.
 *
 * This function retrieves the size of the option button as a pair of doubles.
 *
 * @return A pair of doubles representing the size of the option button (width,
 * height).
 */
std::pair<double, double> OptionButton::getSize() const {
    return this->_size;
}

/**
 * @brief Set the size of the OptionButton component.
 *
 * This function sets the size of the option button as a pair of doubles.
 *
 * @param size A pair of doubles representing the new size of the option button
 * (width, height).
 */
void OptionButton::setSize(std::pair<double, double> size) {
    this->_size = size;
}

/**
 * @brief Get the shape of the OptionButton component.
 *
 * This function gets the sf::RectangleShape of the option button.
 *
 * @return An sf::RectangleShape object representing the option button.
 */
sf::RectangleShape& OptionButton::getShape() {
    return this->_optionbutton;
}

/**
 * @brief Set the shape of the OptionButton component.
 *
 * This function sets the sf::RectangleShape of the option button.
 *
 * @param shape An sf::RectangleShape object representing the option button.
 */
void OptionButton::setShape(const sf::RectangleShape& shape) {
    this->_optionbutton = shape;
}

/**
 * @brief Get whether the OptionButton component is loaded.
 *
 * This function checks if the OptionButton component has been initialized.
 *
 * @return True if the OptionButton is loaded, false otherwise.
 */
bool OptionButton::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Set whether the OptionButton component is loaded.
 *
 * This function sets the loaded state of the OptionButton component.
 */
void OptionButton::setIsLoaded() {
    this->_isLoad = !this->_isLoad;
}

/**
 * @brief Get whether the OptionButton component is checked.
 *
 * This function checks if the OptionButton component has been activated.
 *
 * @return True if the OptionButton is active, false otherwise.
 */
bool OptionButton::getChecked() const {
    return this->_isChecked;
}

/**
 * @brief Set whether the OptionButton component is checked.
 *
 * This function sets the activated state of the OptionButton component.
 */
void OptionButton::setChecked() {
    this->_isChecked = !this->_isChecked;
}

/**
 * @brief Set function for callback.
 *
 * This function sets the callback state of the Slider component.
 * @param callback An std::function object representing the function to
 * callback.
 */
void OptionButton::setCallback(std::function<void()> callback) {
    _callback = callback;
}

/**
 * @brief Execute function callback.
 *
 * This function call the function in callback of the Slider component.
 */
void OptionButton::executeCallback() {
    if (_callback) {
        _callback();
    }
}

/**
 * @brief Display the OptionButton component information.
 *
 * This function displays a message indicating that the OptionButton component
 * is being displayed.
 */
void OptionButton::display() const {
    std::cout << "OptionButton component displayed!" << std::endl;
}