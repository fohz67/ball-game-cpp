#include "managers/EntityManager.hpp"
#include <components/Color.hpp>
#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <components/Texture.hpp>
#include "System.hpp"
#include "config/ConfigClient.hpp"

EntityManager& EntityManager::get() {
    static EntityManager instance;
    return instance;
}

void EntityManager::createCell(uint32_t id, uint32_t ownerId, double x,
                               double y, double radius,
                               std::vector<double> color) {
    if (color.size() != 4) {
        color = {255, 255, 255, 255};
    }

    auto newEntity = GameEngine::Entity(id);

    newEntity.addComponent(
        Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newEntity.addComponent(Position({{x, y}}));
    newEntity.addComponent(Color(color));

    entities.emplace(id, std::move(newEntity));
}

void EntityManager::updateCellPosition(uint32_t id, double x, double y) {
    GameEngine::System system;
    std::pair<float, float> position = {x, y};

    system.update(id, entities, GameEngine::UpdateType::Position, position);
}

void EntityManager::createWorld(uint16_t size) {
    auto newEntity = GameEngine::Entity(ConfigClient::World::ID);

    newEntity.addComponent(Shape(ShapeType::Rectangle, {size, size}));
    newEntity.addComponent(Position({{0.0f, 0.0f}}));
    newEntity.addComponent(Color(ConfigClient::World::BACKGROUND_COLOR));

    entities.emplace(ConfigClient::World::ID, std::move(newEntity));
}
