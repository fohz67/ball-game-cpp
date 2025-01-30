/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the `spriteSystem` function, which handles the rendering and
** interaction of sprite components within the game engine.
** Responsibility:
** - Check if an entity has sprite and position components
** - Load sprite resources if not already loaded
** - Render the sprite on the window
** - Update the sprite's properties based on game logic
*/

#include <components/Sprite.hpp>
#include "System.hpp"

/**
 * @brief Loads the sprite component of an entity if it is not already loaded.
 * 
 * This function checks if the sprite component is loaded. If not, it loads the texture from file,
 * sets the texture, texture rect, position, size, and color of the sprite. Finally, it marks
 * the sprite component as loaded.
 * 
 * @param entity The entity containing the sprite component.
 * @param spriteComp The sprite component to be loaded.
 * @param textureComp The texture component to be loaded.
 */
void GameEngine::System::loadSprite(GameEngine::Entity& entity,
                                    auto& spriteComp, auto& textureComp) {
    if (!spriteComp.getIsLoaded()) {
        if (textureComp.getTextureRect().size() == 4) {
            const auto& textureRect = textureComp.getTextureRect();
            spriteComp.getSprite().setTextureRect(
                sf::IntRect(textureRect[0], textureRect[1], textureRect[2],
                            textureRect[3]));
        }
        spriteComp.getSprite().setTexture(textureComp.getTexture());
        setPosition(entity, spriteComp.getSprite());
        if (spriteComp.getSize().first != -1 &&
            spriteComp.getSize().second != -1) {
            spriteComp.getSprite().setScale(spriteComp.getSize().first,
                                            spriteComp.getSize().second);
        }
        setColor(entity, spriteComp.getSprite());
        spriteComp.setIsLoaded(true);
    }
}

/**
 * @brief Renders the sprite component of an entity on the window.
 * 
 * This function checks if the entity has both sprite and texture components. If so, it loads
 * the sprite component and then draws the sprite on the window. If the position component has
 * multiple positions, it draws the sprite at each position. Otherwise, it draws the sprite at
 * the single position.
 * 
 * @param window The render window where the sprite will be drawn.
 * @param entity The entity containing the sprite and texture components.
 */
void GameEngine::System::spriteSystem(sf::RenderWindow& window,
                                      GameEngine::Entity& entity) {
    if (entity.hasComponent<Sprite>() && entity.hasComponent<Texture>()) {
        auto& spriteComp = entity.getComponent<Sprite>();
        auto& textureComp = entity.getComponent<Texture>();
        if (!textureComp.getIsLoaded()) {
            textureComp.getTexture().loadFromFile(textureComp.getTexturePath());
            textureComp.setIsLoaded(true);
        }
        loadSprite(entity, spriteComp, textureComp);
        if (entity.getComponent<Position>().getPositions().size() > 1) {
            auto& positionComp = entity.getComponent<Position>();
            for (auto& position : positionComp.getPositions()) {
                spriteComp.getSprite().setPosition(position.first,
                                                   position.second);
                window.draw(spriteComp.getSprite());
            }
        } else {
            window.draw(spriteComp.getSprite());
        }
    }
}
