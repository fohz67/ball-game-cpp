#include "components/HUD.hpp"
#include <iostream>
#include "components/Color.hpp"
#include "components/Position.hpp"
#include "components/Shape.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "managers/EntityManager.hpp"

HUD& HUD::get() {
    static HUD instance;
    return instance;
}

void HUD::create() {
    createLeaderboard();
    createStats();
    createChatBox();
}

void HUD::createLeaderboard() {
    increaseId();

    auto newEntity = GEngine::Entity(currentId);

    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::Leaderboard::WIDTH, ConfigClient::HUD::Leaderboard::HEIGHT}));
    newEntity.addComponent(Position(
        {{GameClient::get().getWindow().getSize().x -
              (ConfigClient::HUD::Leaderboard::WIDTH + ConfigClient::HUD::Leaderboard::PADDING),
          ConfigClient::HUD::Leaderboard::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::Leaderboard::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));

    std::cout << "Leaderboard created" << std::endl;
}

void HUD::createStats() {
    increaseId();

    auto newEntity = GEngine::Entity(currentId);

    newEntity.addComponent(Shape(
        ShapeType::Rectangle, {ConfigClient::HUD::Stats::WIDTH, ConfigClient::HUD::Stats::HEIGHT}));
    newEntity.addComponent(
        Position({{ConfigClient::HUD::Stats::PADDING, ConfigClient::HUD::Stats::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::Stats::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));

    std::cout << "Stats created" << std::endl;
}

void HUD::createChatBox() {
    increaseId();

    auto newEntity = GEngine::Entity(currentId);

    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::ChatBox::WIDTH, ConfigClient::HUD::ChatBox::HEIGHT}));
    newEntity.addComponent(Position(
        {{GameClient::get().getWindow().getSize().x -
              (ConfigClient::HUD::ChatBox::WIDTH + ConfigClient::HUD::Leaderboard::PADDING),
          GameClient::get().getWindow().getSize().y -
              (ConfigClient::HUD::ChatBox::HEIGHT + ConfigClient::HUD::Leaderboard::PADDING)}}));
    newEntity.addComponent(Color(ConfigClient::HUD::ChatBox::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));

    std::cout << "ChatBox created" << std::endl;
}

void HUD::increaseId() {
    currentId += ConfigClient::Network::ENTITY_LINKING_BIAS;
}

void HUD::setMass(long newMass) {}

void HUD::setScore(long newScore) {}
