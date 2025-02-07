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

EntityManager& EntityManager::get()
{
    static EntityManager instance;
    return instance;
}

const void EntityManager::createCell(const uint32_t id,
                                     const double x,
                                     const double y,
                                     const double radius,
                                     std::vector<double> color,
                                     const std::string nickname)
{
    if (color.size() != 4)
    {
        color = {255, 255, 255, 255};
    }

    GameEngine::Entity newCell(id);

    newCell.addComponent(Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newCell.addComponent(Position({{x, y}}));
    newCell.addComponent(Color(color));

    entities.emplace(id, std::move(newCell));
}

const void EntityManager::createNickname(const uint32_t id,
                                         const double x,
                                         const double y,
                                         const double radius,
                                         const std::string nickname)
{
    auto newNickname = GameEngine::Entity(id + ConfigClient::Network::ENTITY_LINKING_BIAS);

    newNickname.addComponent(
        Text(nickname,
             "assets/fonts/" + ConfigClient::Player::Nickname::FONT_FAMILY + "/" +
                 std::to_string(ConfigClient::Player::Nickname::FONT_WEIGHT) + ".ttf",
             ConfigClient::Player::Nickname::TEXT_SIZE));
    newNickname.addComponent(Position({{x + radius, y + radius}}));
    newNickname.addComponent(Link(id));

    auto linkingBias = linkedEntitiesBiases.find(id)->second;

    entities.emplace(id + ConfigClient::Network::ENTITY_LINKING_BIAS * linkingBias,
                     std::move(newNickname));
    linkedEntitiesBiases.emplace(id, linkingBias + 1);
}

const void EntityManager::createWorld(const uint16_t size)
{
    GameEngine::Entity newWorld(ConfigClient::World::ID);
    const std::pair<double, double> position = {0.0f, 0.0f};

    newWorld.addComponent(Shape(ShapeType::Rectangle, {size, size}));
    newWorld.addComponent(Position({position}));
    newWorld.addComponent(Color(ConfigClient::World::BACKGROUND_COLOR));

    entities.emplace(ConfigClient::World::ID, std::move(newWorld));
}

const void EntityManager::updateCell(const uint32_t id,
                                     const double x,
                                     const double y,
                                     const double radius,
                                     const bool isNickname)
{
    GameEngine::System system;

    const std::pair<double, double> position = {x, y};

    system.update(id, entities, GameEngine::UpdateType::Position, position);
    system.update(id, entities, GameEngine::UpdateType::ShapeSize, radius);
}

const void EntityManager::removeEntity(const double id)
{
    if (entities.contains(id))
    {
        entities.erase(id);
    }

    if (linkedEntitiesBiases.contains(id))
    {
        linkedEntitiesBiases.erase(id);
    }
}

std::map<double, GameEngine::Entity> EntityManager::getGameEntities() const
{
    std::map<double, GameEngine::Entity> gameEntities;

    for (const auto& [id, entity] : entities)
    {
        if (id <= ConfigClient::World::ID || id > ConfigClient::World::ID + 1)
        {
            gameEntities.emplace(id, entity);
        }
    }

    return gameEntities;
}

std::map<double, GameEngine::Entity> EntityManager::getHUDEntities() const
{
    std::map<double, GameEngine::Entity> hudEntities;

    for (const auto& [id, entity] : entities)
    {
        if (id > ConfigClient::World::ID && id <= ConfigClient::World::ID + 1)
        {
            hudEntities.emplace(id, entity);
        }
    }

    return hudEntities;
}
