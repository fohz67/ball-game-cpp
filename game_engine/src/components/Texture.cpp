/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Texture.cpp
**
** Represents a texture component with a path to a graphical asset.
** Provides methods to get and set the texture path.
*/

#include "components/Texture.hpp"
#include <iostream>

/**
 * @brief Constructor for the Texture component.
 *
 * This constructor initializes the texture component with the given texture
 * file path.
 *
 * @param texturePath The path to the texture file.
 * @param textureRect
 */
Texture::Texture(const std::string& texturePath,
                 const std::vector<int>& textureRect)
    : _texturePath(texturePath), _textureRect(textureRect) {}

/**
 * @brief Get the texture file path.
 *
 * This function retrieves the file path of the texture.
 *
 * @return The file path of the texture.
 */
std::string Texture::getTexturePath() const {
    return this->_texturePath;
}

/**
 * @brief Set the texture file path.
 *
 * This function sets the file path for the texture.
 *
 * @param texturePath The new file path for the texture.
 */
void Texture::setTexturePath(const std::string& texturePath) {
    this->_texturePath = texturePath;
}

/**
 * @brief Get the texture rectangle.
 *
 * This function retrieves the texture rectangle.
 *
 * @return The texture rectangle.
 */
std::vector<int> Texture::getTextureRect() const {
    return this->_textureRect;
}

/**
 * @brief Get whether the Texture component is loaded.
 *
 * This function checks if the Texture component has been initialized.
 *
 * @return True if the Texture is loaded, false otherwise.
 */
bool Texture::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Set whether the Texture component is loaded.
 *
 * This function sets the loaded state of the Texture component.
 */
void Texture::setIsLoaded(const bool isLoaded) {
    this->_isLoad = isLoaded;
}

/**
 * @brief Get the texture object.
 *
 * This function retrieves the texture object.
 *
 * @return The texture object.
 */
sf::Texture& Texture::getTexture() {
    return this->_texture;
}

/**
 * @brief Set the texture object.
 *
 * This function sets the texture object.
 *
 * @param texture The new texture object.
 */
void Texture::setTexture(const sf::Texture& texture) {
    this->_texture = texture;
}

/**
 * @brief Display the Texture component information.
 *
 * This function displays a message indicating that the texture component is
 * being displayed.
 */
void Texture::display() const {
    std::cout << "Texture component displayed!" << std::endl;
}

/**
 * @brief Destructor for the Texture component.
 *
 * This destructor cleans up any resources used by the texture component.
 */
Texture::~Texture() {}
