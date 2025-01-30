/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonRect.cpp
**
** The ButtonRect class represents a UI rectangle ButtonRect with a size.
** It holds a `size` as a `std::pair<double, double>` for
the ButtonRect's
** width and height.
** The constructor allows initializing these attributes with default values.
*/

#include "components/ButtonRect.hpp"

/**
 * @brief Constructor for the ButtonRect component.
 *
 * This constructor initializes the ButtonRect component with the specified text
 * and size.
 *
 * @param text A string representing the text on the ButtonRect.
 * @param size A pair of doubles representing the size of the ButtonRect (width,
 * height).
 */

ButtonRect::ButtonRect(const std::pair<int, int>& sizeRect, sf::Color color,
                       bool showOutline)
    : _size(sizeRect), _color(color), _showOutline(showOutline) {}

/**
 * @brief Destructor for the ButtonRect component.
 *
 * This destructor cleans up any resources used by the ButtonRect component.
 */
ButtonRect::~ButtonRect() {}

/**
 * @brief Get the ButtonRect shape of the ButtonRect component.
 *
 * This function returns a reference to the RectangleShape representing the
 * ButtonRect.
 *
 * @return A reference to an sf::RectangleShape.
 */
sf::RectangleShape& ButtonRect::getButtonRect() {
    return this->_buttonRect;
}

/**
 * @brief Get the color of the shape of the ButtonRect component.
 *
 * This function returns a sf::Color to the RectangleShape representing the
 * ButtonRect.
 *
 * @return An sf::Color.
 */
sf::Color ButtonRect::getColor() {
    return _color;
}

/**
 * @brief Get the size of the ButtonRect component.
 *
 * This function retrieves the size of the ButtonRect as a pair of doubles.
 *
 * @return A pair of doubles representing the size of the ButtonRect (width,
 * height).
 */
std::pair<int, int> ButtonRect::getSize() const {
    return this->_size;
}

/**
 * @brief Set the load status of the ButtonRect.
 *
 * This function sets the load status of the ButtonRect.
 *
 * @param isLoaded A boolean indicating whether the ButtonRect is loaded.
 */
void ButtonRect::setIsLoaded(bool isLoaded) {
    this->_isLoad = isLoaded;
}

/**
 * @brief Get the load status of the ButtonRect.
 *
 * This function retrieves the load status of the ButtonRect.
 *
 * @return A boolean indicating if the ButtonRect is loaded.
 */
bool ButtonRect::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Set function for callback.
 *
 * This function sets the callback state of the Slider component.
 * @param callback An std::function object representing the function to
 * callback.
 */
void ButtonRect::setCallback(std::function<void()> callback) {
    _callback = callback;
}

/**
 * @brief Get the outline status of the ButtonRect.
 *
 * This function retrieves the outline status of the ButtonRect.
 *
 * @return A boolean indicating if the ButtonRect outline is show.
 */
bool ButtonRect::getShowOutline() const {
    return this->_showOutline;
}

/**
 * @brief Execute function callback.
 *
 * This function call the function in callback of the Slider component.
 */
void ButtonRect::executeCallback() {
    if (_callback) {
        _callback();
    }
}

/**
 * @brief Display the ButtonRect component information.
 *
 * This function displays a message indicating that the ButtonRect component is
 * being displayed.
 */
void ButtonRect::display() const {
    std::cout << "ButtonRect component displayed!" << std::endl;
}

/**
 * @brief Check if the ButtonRect is hovered.
 *
 * This function checks if the given mouse position is over the ButtonRect.
 *
 * @param mousePos A vector representing the mouse position (x, y).
 * @return True if the ButtonRect is hovered, false otherwise.
 */
bool ButtonRect::isHovered(sf::Vector2i mousePos) {
    return this->_buttonRect.getGlobalBounds().contains(mousePos.x, mousePos.y);
}
