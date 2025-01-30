/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Components.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

class Component {
  public:
    virtual ~Component() = default;
    virtual void display() const = 0;
};
