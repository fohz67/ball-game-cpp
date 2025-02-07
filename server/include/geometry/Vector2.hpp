#pragma once

#include <cmath>
#include <ostream>

#include "geometry/FastInvSqrt.hpp"

class Vector2
{
   public:
    double x;
    double y;

    Vector2() : x(0), y(0) {}
    Vector2(double x, double y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }

    Vector2& operator+=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2 operator-(const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }

    Vector2& operator-=(const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vector2& operator-=(const double val)
    {
        x -= val;
        y -= val;
        return *this;
    }

    Vector2 operator*(double scalar) const { return Vector2(x * scalar, y * scalar); }

    Vector2& operator*=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 operator/(double scalar) const { return Vector2(x / scalar, y / scalar); }

    Vector2& operator/=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    double magnitude() const { return 1.0f / FIS(x * x + y * y); }

    Vector2 normalized() const
    {
        double mag = magnitude();
        return (mag == 0) ? Vector2(0, 0) : Vector2(x / mag, y / mag);
    }

    double dot(const Vector2& rhs) const { return x * rhs.x + y * rhs.y; }
};
