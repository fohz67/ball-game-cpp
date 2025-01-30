/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Shape.cpp
**
** The Shape class represents the visual and geometric representation of an
*object.
** It defines properties such as dimensions, color, and texture coordinates.
** Shapes can be used to render objects on the screen and interact with other
*components,
** like physics or collision systems.
** This class provides methods to create, modify, and retrieve information about
*shapes.
*/

#include "components/Shape.hpp"
#include <iostream>

/**
 * @brief Constructor for the Shape class.
 * @param type The type of the shape.
 * @param size The size of the shape as a pair of doubles.
 * @param radius The radius of the shape.
 */
Shape::Shape(const ShapeType type, const std::pair<double, double>& size,
             const float radius)
    : _type(type), _size(size), _radius(radius) {}

/**
 * @brief Gets the size of the shape.
 * @return The size of the shape as a pair of doubles.
 */
std::pair<double, double> Shape::getSize() const {
    return _size;
}

/**
 * @brief Sets the size of the shape.
 * @param size The new size of the shape as a pair of doubles.
 */
void Shape::setSize(const std::pair<double, double>& size) {
    _size = size;
}

/**
 * @brief Displays the shape component information.
 */
void Shape::display() const {
    std::cout << "Shape component displayed!" << std::endl;
}

/**
 * @brief Gets the type of the shape.
 * @return The type of the shape.
 */
ShapeType Shape::getShapeType() const {
    return _type;
}

/**
 * @brief Gets the rectangle shape.
 * @return The rectangle shape.
 */
sf::RectangleShape& Shape::getRect() {
    return _rect;
}

/**
 * @brief Gets the circle shape.
 * @return The circle shape.
 */
sf::CircleShape& Shape::getCircle() {
    return _circle;
}

/**
 * @brief Gets whether the shape is loaded.
 * @return True if the shape is loaded, false otherwise.
 */
bool Shape::getIsLoaded() const {
    return _isLoad;
}

/**
 * @brief Sets whether the shape is loaded.
 * @param isLoad The new loaded state of the shape.
 */
void Shape::setIsLoaded(const bool isLoad) {
    _isLoad = isLoad;
}

/**
 * @brief Gets the radius of the shape.
 * @return The radius of the shape.
 */
float Shape::getRadius() const {
    return _radius;
}

/**
 * @brief Sets the shape of the rectangle.
 * @param rect The new rectangle shape.
 */
void Shape::setShape(const sf::RectangleShape& rect) {
    _rect = rect;
}

/**
 * @brief Sets the shape of the circle.
 * @param circle The new circle shape.
 */
void Shape::setShape(const sf::CircleShape& circle) {
    _circle = circle;
}

/**
 * @brief Destructor for the Shape class.
 */
Shape::~Shape() {}