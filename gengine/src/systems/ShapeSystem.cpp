#include <components/Shape.hpp>
#include <components/Texture.hpp>
#include "System.hpp"

#include <unordered_map>

void GEngine::System::loadRectangle(GEngine::Entity& entity, auto& shapeComp) {
    if (!shapeComp.isLoaded()) {
        shapeComp.getRect().setSize(
            sf::Vector2f(shapeComp.getSize().first, shapeComp.getSize().second));

        setPosition(entity, shapeComp.getRect());
        setColor(entity, shapeComp.getRect());

        if (entity.hasComponent<Texture>()) {
            auto& textureComp = entity.getComponent<Texture>();
            static std::unordered_map<std::string, sf::Texture> textureCache;

            if (!textureComp.isLoaded()) {
                if (textureCache.find(textureComp.getTexturePath()) == textureCache.end()) {
                    sf::Texture texture;

                    if (texture.loadFromFile(textureComp.getTexturePath())) {
                        textureCache[textureComp.getTexturePath()] = std::move(texture);
                    }
                }

                textureComp.getTexture() = textureCache[textureComp.getTexturePath()];
                textureComp.setLoaded(true);
            }

            shapeComp.getRect().setTexture(&textureComp.getTexture());

            if (textureComp.getTextureRect().size() == 4) {
                const auto& textureRect = textureComp.getTextureRect();

                shapeComp.getRect().setTextureRect(
                    sf::IntRect(textureRect[0], textureRect[1], textureRect[2], textureRect[3]));
            }
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

        if (entity.hasComponent<Texture>() && !entity.getComponent<Texture>().isLoaded()) {
            auto& textureComp = entity.getComponent<Texture>();
            textureComp.getTexture().loadFromFile(textureComp.getTexturePath());

            if (textureComp.getTextureRect().size() == 4) {
                const auto& textureRect = textureComp.getTextureRect();
                shapeComp.getCircle().setTextureRect(
                    sf::IntRect(textureRect[0], textureRect[1], textureRect[2], textureRect[3]));
            }

            shapeComp.getCircle().setTexture(&textureComp.getTexture());
            textureComp.setLoaded(true);
        }

        shapeComp.setLoaded(true);
    }
}

void GEngine::System::shapeSystem(sf::RenderWindow& window, GEngine::Entity& entity) {
    if (entity.hasComponent<Shape>() && entity.hasComponent<Position>()) {
        auto& shapeComp    = entity.getComponent<Shape>();
        auto& positionComp = entity.getComponent<Position>();

        static std::unordered_map<uint32_t, std::pair<float, float>> lastPositions;

        if (shapeComp.getShapeType() == Rectangle) {
            loadRectangle(entity, shapeComp);

            auto newPos = positionComp.getPositions()[0];
            if (lastPositions[entity.getEntityId()] != newPos) {
                shapeComp.getRect().setPosition(newPos.first, newPos.second);
                lastPositions[entity.getEntityId()] = newPos;
            }

            window.draw(shapeComp.getRect());
        }

        if (shapeComp.getShapeType() == Circle) {
            loadCircle(entity, shapeComp);

            auto newPos = positionComp.getPositions()[0];
            if (lastPositions[entity.getEntityId()] != newPos) {
                shapeComp.getCircle().setPosition(newPos.first, newPos.second);
                lastPositions[entity.getEntityId()] = newPos;
            }

            window.draw(shapeComp.getCircle());
        }
    }
}
