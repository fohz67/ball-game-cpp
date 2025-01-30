#include "entity/EntityManager.hpp"
#include "System.hpp"
#include "game/GameConfigClient.hpp"

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

void EntityManager::createCell(int id, float x, float y, float radius, std::vector<double> color) {
    if (color.size() != 4) {
        color = {255, 255, 255, 255};
    }
    auto newEntity = GameEngine::Entity(id);
    newEntity.addComponent(Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newEntity.addComponent(Position({{x, y}}));
    newEntity.addComponent(Color(color));
    entities.emplace(id, std::move(newEntity));
}

void EntityManager::createWorld() {
    auto newEntity = GameEngine::Entity(GameConfigClient::World::ID);
    newEntity.addComponent(Shape(ShapeType::Rectangle, {GameConfigClient::World::WIDTH, GameConfigClient::World::HEIGHT}));
    newEntity.addComponent(Position({{0.0f, 0.0f}}));
    newEntity.addComponent(Color(GameConfigClient::World::BACKGROUND_COLOR));
    entities.emplace(GameConfigClient::World::ID, std::move(newEntity));
}

void EntityManager::removeEntity(int id) {
    entities.erase(id);
}

void EntityManager::clearEntities() {
    entities.clear();
}
