/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Position.cpp
**
** The Position class represents a 2D position with `x` and `y` coordinates.
** It provides methods to get and set the values of `x` and `y` coordinates.
** The constructor allows initializing the position, and default values are set
*to 0.0f for both coordinates.
*/

#include "components/Position.hpp"
#include <iostream>

/**
 * @brief Constructor for the Position component.
 *
 * This constructor initializes the Position component with the given x and y
 * coordinates.
 *
 * @param positions
 */
Position::Position(const std::vector<std::pair<float, float>>& positions)
    : _positions(positions) {}

/**
 * @brief Destructor for the Position component.
 *
 * This destructor cleans up any resources used by the Position component.
 */
Position::~Position() {}

/**
 * @brief Get all positions.
 *
 * This function retrieves all the positions stored in the Position component.
 *
 * @return A vector of pairs representing the x and y coordinates.
 */
std::vector<std::pair<float, float>> Position::getPositions() const {
    return _positions;
}

/**
 * @brief Get the x-coordinate of the Position component.
 *
 * This function retrieves the x-coordinate of the Position component.
 *
 * @return The x-coordinate of the position.
 */
float Position::getPositionX(const int id) const {
    return this->_positions[id].first;
}

/**
 * @brief Get the y-coordinate of the Position component.
 *
 * This function retrieves the y-coordinate of the Position component.
 *
 * @return The y-coordinate of the position.
 */
float Position::getPositionY(const int id) const {
    return this->_positions[id].second;
}

/**
 * @brief Set the x-coordinate of the Position component.
 *
 * This function sets the x-coordinate of the Position component.
 *
 * @param id
 * @param x The new x-coordinate for the position.
 */
void Position::setPositionX(const int id, const float x) {
    this->_positions[id].first = x;
}

/**
 * @brief Set the y-coordinate of the Position component.
 *
 * This function sets the y-coordinate of the Position component.
 *
 * @param id
 * @param y The new y-coordinate for the position.
 */
void Position::setPositionY(const int id, const float y) {
    this->_positions[id].second = y;
}

/**
 * @brief Add a new position.
 *
 * This function adds a new position to the Position component.
 *
 * @param x The x-coordinate of the new position.
 * @param y The y-coordinate of the new position.
 */
void Position::addPosition(const float x, const float y) {
    this->_positions.emplace_back(x, y);
}

/**
 * @brief Remove a position.
 *
 * This function removes a position from the Position component.
 *
 * @param id The index of the position to be removed.
 */
void Position::removePosition(const int id) {
    this->_positions.erase(this->_positions.begin() + id);
}

/**
 * @brief Display the Position component information.
 *
 * This function displays a message indicating that the Position component is
 * being displayed.
 */
void Position::display() const {
    std::cout << "Position component displayed!" << std::endl;
}