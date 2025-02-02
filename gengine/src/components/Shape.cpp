#include "components/Shape.hpp"
#include <iostream>

Shape::Shape(const ShapeType type, const Point& size,
             const double radius)
    : type(type), size(size), radius(radius) {}

Point Shape::getSize() const {
    return size;
}

ShapeType Shape::getShapeType() const {
    return type;
}

sf::RectangleShape& Shape::getRect() {
    return rectangle;
}

sf::CircleShape& Shape::getCircle() {
    return circle;
}

bool Shape::isLoaded() const {
    return loaded;
}

double Shape::getRadius() const {
    return radius;
}

void Shape::setSize(const Point& val) {
    size = val;
}

void Shape::setLoaded(const bool val) {
    loaded = val;
}

void Shape::setShape(const sf::RectangleShape& val) {
    rectangle = val;
}

void Shape::setShape(const sf::CircleShape& val) {
    circle = val;
}

void Shape::display() const {
    std::cout << "Shape component displayed!" << std::endl;
}
