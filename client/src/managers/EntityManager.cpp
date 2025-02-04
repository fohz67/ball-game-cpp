#include "managers/EntityManager.hpp"
#include <components/Color.hpp>
#include <components/Link.hpp>
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

void EntityManager::createCell(uint32_t            id,
                               double              x,
                               double              y,
                               double              radius,
                               std::vector<double> color,
                               std::string         nickname) {
    if (color.size() != 4) {
        color = {255, 255, 255, 255};
    }

    auto newCell = GEngine::Entity(id);

    newCell.addComponent(Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newCell.addComponent(Position({{x, y}}));
    newCell.addComponent(Color(color));

    entities.emplace(id, std::move(newCell));

    if (nickname.length() > 0) {
        // createNickname(id, x, y, radius, nickname);
    }
}

void EntityManager::createNickname(
    uint32_t id, double x, double y, double radius, std::string nickname) {
    auto newNickname = GEngine::Entity(id + ConfigClient::Network::ENTITY_LINKING_BIAS);

    newNickname.addComponent(
        Text(nickname,
             "assets/fonts/" + ConfigClient::Player::Nickname::FONT_FAMILY + "/" +
                 std::to_string(ConfigClient::Player::Nickname::FONT_WEIGHT) + ".ttf",
             ConfigClient::Player::Nickname::TEXT_SIZE));
    newNickname.addComponent(Position({{x + radius, y + radius}}));
    newNickname.addComponent(Link(id));

    auto linkingBias = entitiesLinkingBiases.find(id)->second;
    entities.emplace(
        id + ConfigClient::Network::ENTITY_LINKING_BIAS * linkingBias, std::move(newNickname));
    entitiesLinkingBiases.emplace(id, linkingBias + 1);
}

void EntityManager::updateCell(uint32_t id, double x, double y, double radius, bool isNickname) {
    GEngine::System           system;
    std::pair<double, double> position = {x, y};

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

void EntityManager::removeEntity(double id) {
    if (entities.contains(id)) {
        entities.erase(id);
    }
    if (entitiesLinkingBiases.contains(id)) {
        entitiesLinkingBiases.erase(id);
    }
}

std::map<double, GEngine::Entity> EntityManager::getGameEntities() const {
    std::map<double, GEngine::Entity> gameEntities;

    for (const auto& [id, entity] : entities) {
        if (id <= ConfigClient::World::ID || id > ConfigClient::World::ID + 1) {
            gameEntities.emplace(id, entity);
        }
    }

    return gameEntities;
}

std::map<double, GEngine::Entity> EntityManager::getHUDEntities() const {
    std::map<double, GEngine::Entity> hudEntities;

    for (const auto& [id, entity] : entities) {
        if (id > ConfigClient::World::ID && id <= ConfigClient::World::ID + 1) {
            hudEntities.emplace(id, entity);
        }
    }

    return hudEntities;
}
