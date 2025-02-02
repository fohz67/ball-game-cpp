/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the `shapeSystem` function, which handles the rendering and
** interaction of shape components within the game engine.
** Responsibility:
** - Check if an entity has shape and position components
** - Load shape resources if not already loaded
** - Render the shape on the window
** - Update the shape's properties based on game logic
*/

#include <components/Shape.hpp>
#include <components/Texture.hpp>
#include "System.hpp"

/**
 * @brief Loads the rectangle component of an entity if it is not already
 * loaded.
 *
 * This function checks if the rectangle component is loaded. If not, it loads
 * the size, position, and color of the rectangle. If the entity has a texture
 * component, it loads the texture and texture rect of the rectangle. Finally,
 * it marks the rectangle component as loaded.
 *
 * @param entity The entity containing the rectangle component.
 * @param shapeComp The rectangle component to be loaded.
 */
void GEngine::System::loadRectangle(GEngine::Entity& entity,
                                       auto& shapeComp) {
    if (!shapeComp.isLoaded()) {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(shapeComp.getSize().first,
                                       shapeComp.getSize().second));
        setPosition(entity, rectangle);
        setColor(entity, rectangle);
        shapeComp.setShape(rectangle);
        if (entity.hasComponent<Texture>() &&
            !entity.getComponent<Texture>().isLoaded()) {
            auto& textureComp = entity.getComponent<Texture>();
            textureComp.getTexture().loadFromFile(textureComp.getTexturePath());
            if (textureComp.getTextureRect().size() == 4) {
                const auto& textureRect = textureComp.getTextureRect();
                shapeComp.getRect().setTextureRect(
                    sf::IntRect(textureRect[0], textureRect[1], textureRect[2],
                                textureRect[3]));
            }
            shapeComp.getRect().setTexture(&textureComp.getTexture());
            textureComp.setLoaded(true);
        }
        shapeComp.setLoaded(true);
    }
}

/**
 * @brief Loads the circle component of an entity if it is not already loaded.
 *
 * This function checks if the circle component is loaded. If not, it loads the
 * radius, position, and color of the circle. If the entity has a texture
 * component, it loads the texture and texture rect of the circle. Finally, it
 * marks the circle component as loaded.
 *
 * @param entity The entity containing the circle component.
 * @param shapeComp The circle component to be loaded.
 */
void GEngine::System::loadCircle(GEngine::Entity& entity,
                                    auto& shapeComp) {
    if (!shapeComp.isLoaded()) {
        sf::CircleShape circle;
        circle.setRadius(shapeComp.getRadius());
        setPosition(entity, circle);
        setColor(entity, circle);
        shapeComp.setShape(circle);
        if (entity.hasComponent<Texture>() &&
            !entity.getComponent<Texture>().isLoaded()) {
            auto& textureComp = entity.getComponent<Texture>();
            textureComp.getTexture().loadFromFile(textureComp.getTexturePath());
            if (textureComp.getTextureRect().size() == 4) {
                const auto& textureRect = textureComp.getTextureRect();
                shapeComp.getCircle().setTextureRect(
                    sf::IntRect(textureRect[0], textureRect[1], textureRect[2],
                                textureRect[3]));
            }
            shapeComp.getCircle().setTexture(&textureComp.getTexture());
            textureComp.setLoaded(true);
        }
        shapeComp.setLoaded(true);
    }
}

/**
 * @brief Renders the shape component of an entity on the window.
 *
 * This function checks if the entity has both shape and position components. If
 * so, it loads the shape component and then draws the shape on the window. If
 * the shape component is a rectangle, it draws the rectangle. If the shape
 * component is a circle, it draws the circle.
 *
 * @param window The render window where the shape will be drawn.
 * @param entity The entity containing the shape and position components.
 */
void GEngine::System::shapeSystem(sf::RenderWindow& window,
                                     GEngine::Entity& entity) {
    if (entity.hasComponent<Shape>() && entity.hasComponent<Position>()) {
        auto& shapeComp = entity.getComponent<Shape>();
        if (shapeComp.getShapeType() == Rectangle) {
            loadRectangle(entity, shapeComp);
            window.draw(shapeComp.getRect());
        }
        if (shapeComp.getShapeType() == Circle) {
            loadCircle(entity, shapeComp);
            window.draw(shapeComp.getCircle());
        }
    }
}
