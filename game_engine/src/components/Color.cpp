/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Color.cpp
**
** The Color class represents a color for an entity in the game.
** It holds the color as a vector of doubles representing RGB values.
** The constructor allows initializing the color with a given vector of values
*(e.g., RGB).
*/

#include "components/Color.hpp"
#include <iostream>

/**
 * @brief Constructor for the Color component.
 *
 * This constructor initializes the Color component with a given color.
 * The color is represented as a vector of doubles (e.g., [R, G, B, A]).
 *
 * @param color A vector of doubles representing the color (e.g., [R, G, B, A]).
 */
Color::Color(const std::vector<double>& color) : _initColor(color) {}

/**
 * @brief Destructor for the Color component.
 *
 * This destructor cleans up any resources used by the Color component.
 */
Color::~Color() {}

/**
 * @brief Get the color of the Color component.
 *
 * This function retrieves the color of the entity as a vector of doubles.
 *
 * @return A vector of doubles representing the color (e.g., [R, G, B, A]).
 */
std::vector<double> Color::getColor() const {
    return this->_initColor;
}

/**
 * @brief Set the color of the Color component.
 *
 * This function sets the color of the entity as a vector of doubles.
 *
 * @param color A vector of doubles representing the new color (e.g., [R, G, B,
 * A]).
 */
void Color::setColor(const std::vector<double>& color) {
    this->_initColor = color;
}

/**
 * @brief Display the Color component information.
 *
 * This function displays a message indicating that the Color component is being
 * displayed.
 */
void Color::display() const {
    std::cout << "Color component displayed!" << std::endl;
}