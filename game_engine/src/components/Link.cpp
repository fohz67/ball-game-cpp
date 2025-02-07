#include "components/Link.hpp"

#include <iostream>

Link::Link(const uint32_t id) : id(id)
{
}

uint32_t Link::getId() const
{
    return this->id;
}

void Link::setId(const uint32_t id)
{
    this->id = id;
}

void Link::display() const
{
    std::cout << "Link component displayed!" << std::endl;
}
