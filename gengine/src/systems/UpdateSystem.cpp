#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <iostream>
#include "System.hpp"

void GEngine::System::updateEntityPosition(const int id,
                                           std::map<int, Entity>& entities,
                                           const std::pair<float, float>& pos,
                                           const int posId) {
    linkSystem(id, entities, pos, posId);

    if (!entities.contains(id)) {
        return;
    }

    Entity& entity = entities.at(id);

    if (entity.hasComponent<Sprite>()) {
        updatePosition(entity, entity.getComponent<Sprite>().getSprite(), pos,
                       posId);
    }

    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();
        sf::FloatRect bounds = textComp.getText().getLocalBounds();

        textComp.getText().setOrigin(bounds.left + bounds.width / 2,
                                     bounds.top + bounds.height / 2);
        textComp.getText().setPosition(pos.first, pos.second);
    }

    if (entity.hasComponent<Shape>()) {
        auto& shapeComp = entity.getComponent<Shape>();

        if (shapeComp.getShapeType() == Rectangle) {
            updatePosition(entity, shapeComp.getRect(), pos, posId);
        } else if (shapeComp.getShapeType() == Circle) {
            updatePosition(entity, shapeComp.getCircle(), pos, posId);
        }
    }
}

void GEngine::System::updateText(Entity& entity, const std::string& text) {
    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();

        textComp.setString(text);
        textComp.getText().setString(text);
        textComp.getFont().loadFromFile(textComp.getFontFile());
    }
}

void GEngine::System::updateTextFont(Entity& entity, const std::string& font) {
    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();

        textComp.getFont().loadFromFile(font);
        textComp.setFontFile(font);
    }
}

void GEngine::System::updateTextSize(const int id,
                                     std::map<int, Entity>& entities,
                                     const unsigned int textSize) {
    Entity& entity = entities.at(id);
    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();
        unsigned int newSize = static_cast<unsigned int>(
            textComp.getInitCharacterSize() * (textSize / 100.0f));

        textComp.setCharacterSize(newSize);
        textComp.getText().setCharacterSize(newSize);

        if (entity.hasComponent<Position>()) {
            auto& positionComp = entity.getComponent<Position>();
            auto currentPos = std::make_pair(positionComp.getPositionX(0),
                                             positionComp.getPositionY(0));

            updateEntityPosition(id, entities, currentPos, 0);
        }
    }
}

void GEngine::System::updateTexture(Entity& entity, std::string& texture) {
    if (entity.hasComponent<Texture>()) {
        auto& textureComp = entity.getComponent<Texture>();

        textureComp.setTexturePath(texture);
        textureComp.getTexture().loadFromFile(textureComp.getTexturePath());

        if (entity.hasComponent<Sprite>()) {
            auto& spriteComp = entity.getComponent<Sprite>();
            spriteComp.getSprite().setTexture(textureComp.getTexture());
        }

        if (entity.hasComponent<Shape>()) {
            auto& shapeComp = entity.getComponent<Shape>();

            if (shapeComp.getShapeType() == Circle) {
                shapeComp.getCircle().setTexture(&textureComp.getTexture());
            }

            if (shapeComp.getShapeType() == Rectangle) {
                shapeComp.getRect().setTexture(&textureComp.getTexture());
            }
        }
    }
}

void GEngine::System::updateShapeSize(Entity& entity, double radius) {
    if (entity.hasComponent<Shape>()) {
        auto& shapeComp = entity.getComponent<Shape>();

        if (shapeComp.getShapeType() == Circle) {
            shapeComp.getCircle().setRadius(static_cast<float>(radius));
        } else if (shapeComp.getShapeType() == Rectangle) {
            shapeComp.getRect().setSize({static_cast<float>(radius) * 2,
                                         static_cast<float>(radius) * 2});
        }
    }
}

void GEngine::System::update(const int id, std::map<int, Entity>& entities,
                             const UpdateType type, const std::any& value,
                             const int posId) {
    if (!entities.contains(id)) {
        return;
    }

    Entity& entity = entities.at(id);

    switch (type) {
    case UpdateType::Position: {
        updateEntityPosition(
            id, entities, std::any_cast<std::pair<float, float>>(value), posId);
        break;
    }
    case UpdateType::Text: {
        updateText(entity, std::any_cast<std::string>(value));
        break;
    }
    case UpdateType::TextSize: {
        updateTextSize(id, entities, std::any_cast<unsigned int>(value));
        break;
    }
    case UpdateType::TextFont: {
        updateTextFont(entity, std::any_cast<std::string>(value));
        break;
    }
    case UpdateType::Texture: {
        auto texture = std::any_cast<std::string>(value);
        updateTexture(entity, texture);
        break;
    }
    case UpdateType::ShapeSize: {
        updateShapeSize(entity, std::any_cast<double>(value));
        break;
    }
    default:
        break;
    }
}
