/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Texture.hpp
*/

#pragma once

#include <string>
#include "Components.hpp"

class Texture : public Component {
  public:
    Texture(const std::string& texturePath = "",
            const std::vector<int>& textureRect = {});
    ~Texture();
    std::string getTexturePath() const;
    void setTexturePath(const std::string& texturePath);
    bool getIsLoaded() const;
    void setIsLoaded(bool isLoaded);
    sf::Texture& getTexture();
    std::vector<int> getTextureRect() const;
    void setTexture(const sf::Texture& texture);
    void display() const override;

  protected:
  private:
    std::string _texturePath;
    std::vector<int> _textureRect;
    sf::Texture _texture;
    bool _isLoad = false;
};
