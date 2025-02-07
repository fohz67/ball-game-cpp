#include "components/Sprite.hpp"

#include <iostream>

Sprite::Sprite(const Point& size) : size(size) {}

std::string Sprite::getTexturePath() const { return this->texturePath; }

Point Sprite::getSize() const { return this->size; }

bool Sprite::isLoaded() const { return this->loaded; }

sf::Sprite& Sprite::getSprite() { return this->sprite; }

void Sprite::setTexturePath(const std::string& val) { this->texturePath = val; }

void Sprite::setSize(const Point& val) { this->size = val; }

void Sprite::setLoaded(const bool val) { this->loaded = val; }

void Sprite::setSprite(const sf::Sprite& val) { this->sprite = val; }

void Sprite::display() const { std::cout << "Sprite component displayed!" << std::endl; }
