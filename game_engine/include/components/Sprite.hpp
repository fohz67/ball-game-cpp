/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Sprite.hpp
*/

#pragma once

#include "Components.hpp"
#include "Texture.hpp"

#include <string>
#include <vector>

class Sprite : public Component {
  public:
    Sprite(const std::pair<float, float>& size = {-1, -1});
    ~Sprite();
    std::string getTexturePath() const;
    void setTexturePath(const std::string& texturePath);
    std::pair<float, float> getSize() const;
    void setSize(const std::pair<float, float>& size);
    bool getIsLoaded() const;
    void setIsLoaded(bool isLoaded);
    sf::Sprite& getSprite();
    void setSprite(const sf::Sprite& sprite);
    void display() const override;

  private:
    std::string _texturePath;
    std::pair<float, float> _size;
    sf::Sprite _sprite;
    bool _isLoad = false;
};
