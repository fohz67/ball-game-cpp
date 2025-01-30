/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** System.hpp
*/

#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <any>
#include <components/Color.hpp>
#include <components/Position.hpp>
#include <memory>
#include "Entity.hpp"

namespace GameEngine {

enum class UpdateType { Position, Text, TextSize, TextFont, Texture };

class System {
  public:
    System();
    ~System();
    void render(sf::RenderWindow& window, std::map<int, Entity>& entities);
    void update(int id, std::map<int, Entity>& entities, UpdateType type,
                const std::any& value, int posId = 0);

  private:
    std::string _fontFile;
    template <typename Drawable>
    void setColor(Entity& entity, Drawable& drawable);
    template <typename Drawable>
    void setPosition(Entity& entity, Drawable& drawable);
    template <typename Drawable>
    void updatePos(Entity& entity, Drawable& drawable,
                   const std::pair<float, float>& pos, const int& posId);
    void updateEntityPosition(int id, std::map<int, Entity>& entities,
                              const std::pair<float, float>& pos, int posId);
    void updateText(Entity& entity, const std::string& text);
    void updateTextSize(int id, std::map<int, Entity>& entities,
                        unsigned int textSize);
    void updateTextFont(Entity& entity, const std::string& font);
    void updateTexture(Entity& entity, std::string& texture);
    void loadSprite(Entity& entity, auto& spriteComp, auto& textureComp);
    void spriteSystem(sf::RenderWindow& window, Entity& entity);
    void linkSystem(int id, std::map<int, Entity>& entities,
                    std::pair<float, float> newLinkedEntityPos, int posId);
    void loadText(Entity& entity, auto& textComp);
    void textSystem(sf::RenderWindow& window, Entity& entity);
    void loadRectangle(Entity& entity, auto& shapeComp);
    void loadCircle(Entity& entity, auto& shapeComp);
    void shapeSystem(sf::RenderWindow& window, Entity& entity);
    void buttonSystem(sf::RenderWindow& window, Entity& entity);
    void optionButtonSystem(sf::RenderWindow& window, Entity& entity);
    void sliderSystem(sf::RenderWindow& window, Entity& entity,
                      std::map<int, Entity>& entities);
    void buttonRectSystem(sf::RenderWindow& window, Entity& entity);
};

template <typename Drawable>
void System::setColor(Entity& entity, Drawable& drawable) {
    if (entity.hasComponent<Color>() &&
        entity.getComponent<Color>().getColor().size() == 4) {
        auto& colorComp = entity.getComponent<Color>();
        const auto& color = colorComp.getColor();
        if constexpr (std::is_same_v<Drawable, sf::Sprite>) {
            drawable.setColor(
                sf::Color(color[0], color[1], color[2], color[3]));
        } else if constexpr (std::is_same_v<Drawable, sf::Text> ||
                             std::is_same_v<Drawable, sf::RectangleShape> ||
                             std::is_same_v<Drawable, sf::CircleShape>) {
            drawable.setFillColor(
                sf::Color(color[0], color[1], color[2], color[3]));
        }
    }
}

template <typename Drawable>
void System::setPosition(Entity& entity, Drawable& drawable) {
    if (entity.hasComponent<Position>()) {
        auto& positionComp = entity.getComponent<Position>();
        drawable.setPosition(positionComp.getPositionX(0),
                             positionComp.getPositionY(0));
    }
}

template <typename Drawable>
void System::updatePos(Entity& entity, Drawable& drawable,
                       const std::pair<float, float>& pos, const int& posId) {
    if (entity.hasComponent<Position>()) {
        auto& positionComp = entity.getComponent<Position>();
        positionComp.setPositionX(posId, pos.first);
        positionComp.setPositionY(posId, pos.second);
        drawable.setPosition(pos.first, pos.second);
    }
}

} // namespace GameEngine