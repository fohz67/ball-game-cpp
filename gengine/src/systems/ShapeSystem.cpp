#include <components/Shape.hpp>
#include <components/Texture.hpp>
#include "System.hpp"

void GEngine::System::loadRectangle(GEngine::Entity& entity, auto& shapeComp) {
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

void GEngine::System::loadCircle(GEngine::Entity& entity, auto& shapeComp) {
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
