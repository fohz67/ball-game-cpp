#pragma once

#include <cstdint>
#include "components/Components.hpp"

class Link : public Component {
  public:
    // Constructor / Destructor
    Link(uint32_t id);
    ~Link() = default;

    // Getters
    uint32_t getId() const;

    // Setters
    void setId(const uint32_t val);

    // Methods
    void display() const override;

  private:
    // Attributes
    uint32_t id;
};
