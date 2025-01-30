/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Link.cpp
**
** The Link class manages a connection between two game entities.
** It holds an identifier used to reference the link and provides
** methods to retrieve and update the link's ID. The constructor
** initializes the connection with a given ID, and the destructor
** ensures proper cleanup when the link is no longer in use.
*/

#include "components/Link.hpp"
#include <iostream>

/**
 * @brief Construct a new Link object.
 *
 * @param id The ID of the entity this Link is associated with.
 */
Link::Link(const int id) : _id(id) {}

/**
 * @brief Retrieve the ID of the entity this Link is associated with.
 *
 * @return int The ID of the associated entity.
 */
int Link::getId() const {
    return this->_id;
}

/**
 * @brief Update the ID of the Link component.
 *
 * @param id The new ID of the associated entity.
 */
void Link::setId(const int id) {
    this->_id = id;
}

/**
 * @brief Display information about the Link component.
 *
 * This function outputs a message indicating that the Link component is being displayed.
 */
void Link::display() const {
    std::cout << "Link component displayed!" << std::endl;
}

/**
 * @brief Destroy the Link object.
 */
Link::~Link() {}