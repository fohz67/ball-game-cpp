#pragma once

#include <SFML/Graphics.hpp>

class Component {
  public:
    // Constructor / Destructor
    virtual ~Component() = default;

    // Methods
    virtual void display() const = 0;
};
