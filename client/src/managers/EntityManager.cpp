#include "managers/EntityManager.hpp"
#include <components/Color.hpp>
#include <components/Link.hpp>
#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <components/Texture.hpp>
#include "System.hpp"
#include <iostream>
#include "config/ConfigClient.hpp"

EntityManager& EntityManager::get() {
    static EntityManager instance;
    return instance;
}

void EntityManager::createCell(uint32_t id, double x, double y, double radius,
                               std::vector<double> color,
                               std::string nickname) {
    if (color.size() != 4) {
        color = {255, 255, 255, 255};
    }

    auto newCell = GEngine::Entity(id);

    newCell.addComponent(
        Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newCell.addComponent(Position({{x, y}}));
    newCell.addComponent(Color(color));

    entities.emplace(id, std::move(newCell));

    if (nickname.length() > 0) {        
        auto newNickname = GEngine::Entity(id + ConfigClient::Network::ENTITY_LINKING_BIAS);

        newNickname.addComponent(Text(
            nickname, "assets/fonts/Inter_Bold.ttf", 10));
        newNickname.addComponent(Position({{x, y}}));
        newNickname.addComponent(Link(id));
        
        entities.emplace(id + ConfigClient::Network::ENTITY_LINKING_BIAS, std::move(newNickname));
    }
}

void EntityManager::updateCell(uint32_t id, double x, double y, double radius, bool isNickname) {
    GEngine::System system;
    std::pair<float, float> position = {x, y};

    system.update(id, entities, GEngine::UpdateType::Position, position);
    system.update(id, entities, GEngine::UpdateType::ShapeSize, radius);
}

void EntityManager::createWorld(uint16_t size) {
    auto newEntity = GEngine::Entity(ConfigClient::World::ID);

    newEntity.addComponent(Shape(ShapeType::Rectangle, {size, size}));
    newEntity.addComponent(Position({{0.0f, 0.0f}}));
    newEntity.addComponent(Color(ConfigClient::World::BACKGROUND_COLOR));

    entities.emplace(ConfigClient::World::ID, std::move(newEntity));
}

void EntityManager::removeEntity(uint32_t id) {
    entities.erase(id);
}
