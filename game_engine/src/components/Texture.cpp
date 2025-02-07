#include "components/Texture.hpp"

#include <iostream>

Texture::Texture(const std::string& texturePath, const std::vector<int>& textureRect)
    : texturePath(texturePath), textureRect(textureRect)
{
}

std::string Texture::getTexturePath() const { return this->texturePath; }

std::vector<int> Texture::getTextureRect() const { return this->textureRect; }

bool Texture::isLoaded() const { return this->loaded; }

sf::Texture& Texture::getTexture() { return this->texture; }

void Texture::setTexturePath(const std::string& val) { this->texturePath = val; }

void Texture::setLoaded(const bool val) { this->loaded = val; }

void Texture::setTexture(const sf::Texture& val) { this->texture = val; }

void Texture::display() const { std::cout << "Texture component displayed!" << std::endl; }
