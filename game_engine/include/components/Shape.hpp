#pragma once

#include <utility>

#include "components/Components.hpp"
#include "components/Point.hpp"

enum ShapeType
{
    Circle,
    Rectangle
};

class Shape : public Component
{
   public:
    // Constants
    static inline Point DEFAULT_SIZE = {0.0, 0.0};
    static constexpr double DEFAULT_RADIUS = 1.0;

    // Constructor / Destructor
    Shape(ShapeType type = Rectangle,
          const Point& size = DEFAULT_SIZE,
          double radius = DEFAULT_RADIUS);
    ~Shape() = default;

    // Getters
    sf::RectangleShape& getRect();
    sf::CircleShape& getCircle();
    bool isLoaded() const;
    double getRadius() const;
    ShapeType getShapeType() const;
    Point getSize() const;

    // Setters
    void setShape(const sf::RectangleShape& val);
    void setShape(const sf::CircleShape& val);
    void setLoaded(const bool val);
    void setSize(const Point& val);

    // Methods
    void display() const override;

   private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    ShapeType type;
    sf::RectangleShape rectangle;
    sf::CircleShape circle;
    Point size;
    double radius;
    bool loaded = DEFAULT_LOADED;
};
