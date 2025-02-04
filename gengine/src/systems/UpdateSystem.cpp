#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include "System.hpp"

void GEngine::System::updateEntityPosition(const int                      id,
                                           std::map<double, Entity>&      entities,
                                           const std::pair<double, double>& pos,
                                           const int                      posId) {
    linkSystem(id, entities, pos, posId);

    auto it = entities.find(id);
    if (it == entities.end())
        return;

    Entity& entity = it->second;

    if (entity.hasComponent<Sprite>()) {
        updatePosition(entity, entity.getComponent<Sprite>().getSprite(), pos, posId);
    }

    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();
        static std::unordered_map<uint32_t, std::pair<double, double>> lastPositions;

        if (lastPositions[entity.getEntityId()] != pos) {
            sf::FloatRect bounds = textComp.getText().getLocalBounds();
            textComp.getText().setOrigin(
                bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
            textComp.getText().setPosition(pos.first, pos.second);
            lastPositions[entity.getEntityId()] = pos;
        }
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
    static std::unordered_map<std::string, sf::Font> fontCache;

    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();

        if (fontCache.find(font) == fontCache.end()) {
            sf::Font newFont;

            if (newFont.loadFromFile(font)) {
                fontCache[font] = std::move(newFont);
            }
        }

        textComp.getText().setFont(fontCache[font]);
        textComp.setFontFile(font);
    }
}

void GEngine::System::updateTextSize(const int                 id,
                                     std::map<double, Entity>& entities,
                                     const unsigned int        textSize) {
    Entity& entity = entities.at(id);
    if (entity.hasComponent<Text>()) {
        auto& textComp = entity.getComponent<Text>();

        textComp.setCharacterSize(textSize);
        textComp.getText().setCharacterSize(textSize);

        if (entity.hasComponent<Position>()) {
            auto& positionComp = entity.getComponent<Position>();
            auto  currentPos =
                std::make_pair(positionComp.getPositionX(0), positionComp.getPositionY(0));

            updateEntityPosition(id, entities, currentPos, 0);
        }
    }
}

void GEngine::System::updateTexture(Entity& entity, std::string& texture) {
    static std::unordered_map<std::string, sf::Texture> textureCache;

    if (entity.hasComponent<Texture>()) {
        auto& textureComp = entity.getComponent<Texture>();

        if (textureCache.find(texture) == textureCache.end()) {
            sf::Texture newTexture;

            if (newTexture.loadFromFile(texture)) {
                textureCache[texture] = std::move(newTexture);
            }
        }

        textureComp.setTexturePath(texture);
        textureComp.getTexture() = textureCache[texture];

        if (entity.hasComponent<Sprite>()) {
            auto& spriteComp = entity.getComponent<Sprite>();
            spriteComp.getSprite().setTexture(textureCache[texture]);
        }

        if (entity.hasComponent<Shape>()) {
            auto& shapeComp = entity.getComponent<Shape>();

            if (shapeComp.getShapeType() == Circle) {
                shapeComp.getCircle().setTexture(&textureCache[texture]);
            }

            if (shapeComp.getShapeType() == Rectangle) {
                shapeComp.getRect().setTexture(&textureCache[texture]);
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
            shapeComp.getRect().setSize(
                {static_cast<float>(radius) * 2, static_cast<float>(radius) * 2});
        }
    }
}

void GEngine::System::update(const double              id,
                             std::map<double, Entity>& entities,
                             const UpdateType          type,
                             const std::any&           value,
                             const int                 posId) {
    auto it = entities.find(id);
    if (it == entities.end())
        return;

    Entity& entity = it->second;

    switch (type) {
    case UpdateType::Position:
        updateEntityPosition(id, entities, std::any_cast<std::pair<double, double>>(value), posId);
        break;
    case UpdateType::Text:
        updateText(entity, std::any_cast<std::string>(value));
        break;
    case UpdateType::TextSize:
        updateTextSize(id, entities, std::any_cast<unsigned int>(value));
        break;
    case UpdateType::TextFont:
        updateTextFont(entity, std::any_cast<std::string>(value));
        break;
    case UpdateType::Texture: {
        auto val = std::any_cast<std::string>(value);
        updateTexture(entity, val);
        break;
    }
    case UpdateType::ShapeSize:
        updateShapeSize(entity, std::any_cast<double>(value));
        break;
    default:
        break;
    }
}
