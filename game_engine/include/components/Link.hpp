/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Link.hpp
*/

#pragma once
#include "Components.hpp"

class Link : public Component {
  public:
    Link(int id);
    ~Link();
    int getId() const;
    void setId(int id);
    void display() const override;

  private:
    int _id;
};
