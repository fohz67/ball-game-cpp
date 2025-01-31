#include "entity/EntityManager.hpp"
#include "ConfigClient.hpp"
#include "System.hpp"

EntityManager& EntityManager::get() {
    static EntityManager instance;
    return instance;
}

void EntityManager::setEntities(std::map<int, GameEngine::Entity> entities) {
    entities = entities;
}

std::map<int, GameEngine::Entity>& EntityManager::getEntities() {
    return entities;
}

void EntityManager::createCell(int id, float x, float y, float radius,
                               std::vector<double> color) {
    if (color.size() != 4) {
        color = {255, 255, 255, 255};
    }
    GameEngine::System system;
    if (auto search = entities.find(id); search != entities.end()) {
        std::pair<float, float> position = {x, y};
        system.update(id, entities, GameEngine::UpdateType::Position, position);
    } else {
        auto newEntity = GameEngine::Entity(id);
        newEntity.addComponent(
            Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
        newEntity.addComponent(Position({{x, y}}));
        newEntity.addComponent(Color(color));
        entities.emplace(id, std::move(newEntity));
    }
}

void EntityManager::createWorld(int size) {
    auto newEntity = GameEngine::Entity(ConfigClient::World::ID);
    newEntity.addComponent(Shape(ShapeType::Rectangle, {size, size}));
    newEntity.addComponent(Position({{0.0f, 0.0f}}));
    newEntity.addComponent(Color(ConfigClient::World::BACKGROUND_COLOR));
    entities.emplace(ConfigClient::World::ID, std::move(newEntity));
}

void EntityManager::removeEntity(int id) {
    entities.erase(id);
}

void EntityManager::clearEntities() {
    entities.clear();
}
