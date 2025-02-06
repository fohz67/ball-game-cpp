#include "components/HUD.hpp"
#include <iostream>
#include "components/Color.hpp"
#include "components/Position.hpp"
#include "components/Shape.hpp"
#include "components/Text.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/ProtocolClient.hpp"

HUD& HUD::get() {
    static HUD instance;
    return instance;
}

void HUD::create() {
    createLeaderboard();
    createStats();
    createChatBox();
}

void HUD::update() {
    static auto lastUpdate = std::chrono::high_resolution_clock::now();
    auto        now        = std::chrono::high_resolution_clock::now();
    auto        elapsed    = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);

    if (elapsed.count() < 1) {
        return;
    }
    lastUpdate = now;

    ProtocolClient::get().sendPing();
    updateStats();
}

void HUD::createLeaderboard() {
    // Box
    increaseId();

    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::Leaderboard::WIDTH, ConfigClient::HUD::Leaderboard::HEIGHT}));
    newEntity.addComponent(
        Position({{GameClient::get().getWindowSize().x -
                       (ConfigClient::HUD::Leaderboard::WIDTH + ConfigClient::HUD::PADDING),
                   ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    leaderboardEntities.emplace(currentId, std::move(newEntity));

    // Title
    increaseId();

    auto newEntityTitle = GameEngine::Entity(currentId);
    newEntityTitle.addComponent(Text(ConfigClient::HUD::Leaderboard::TITLE,
                                     "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                         std::to_string(ConfigClient::HUD::FONT_WEIGHT) + ".ttf",
                                     ConfigClient::HUD::Leaderboard::TITLE_SIZE,
                                     1));
    newEntityTitle.addComponent(
        Position({{GameClient::get().getWindowSize().x - ConfigClient::HUD::Leaderboard::WIDTH / 2 -
                       ConfigClient::HUD::PADDING,
                   ConfigClient::HUD::PADDING + 40}}));
    newEntityTitle.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntityTitle));
    leaderboardEntities.emplace(currentId, std::move(newEntityTitle));

    // Players List
    float yOffset = ConfigClient::HUD::PADDING + 85;
    auto  players = PlayerManagerClient::get().players;

    for (const auto& player : players) {
        int i = 1;

        increaseId();

        auto newPlayerEntity = GameEngine::Entity(currentId);
        newPlayerEntity.addComponent(Text(std::to_string(i) + ". " + player.getNickname(),
                                          "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                              std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                              ".ttf",
                                          ConfigClient::HUD::Leaderboard::CONTENT_SIZE,
                                          1));
        newPlayerEntity.addComponent(
            Position({{GameClient::get().getWindowSize().x -
                           ConfigClient::HUD::Leaderboard::WIDTH / 2 - ConfigClient::HUD::PADDING,
                       yOffset}}));
        newPlayerEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newPlayerEntity));
        leaderboardEntities.emplace(currentId, std::move(newPlayerEntity));

        yOffset += 50;
        i++;
    }
}

void HUD::createStats() {
    increaseId();

    // Box
    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(Shape(
        ShapeType::Rectangle, {ConfigClient::HUD::Stats::WIDTH, ConfigClient::HUD::Stats::HEIGHT}));
    newEntity.addComponent(Position({{ConfigClient::HUD::PADDING, ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    statsEntity.emplace(currentId, std::move(newEntity));

    // Titles & Values
    float                    yOffset = ConfigClient::HUD::PADDING + 20;
    std::vector<std::string> labels  = {"Score:", "Mass:", "Ping:", "FPS:"};

    for (const auto& label : labels) {
        increaseId();

        // Label
        auto newLabelEntity = GameEngine::Entity(currentId);
        newLabelEntity.addComponent(Text(label,
                                         "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                             std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                             ".ttf",
                                         ConfigClient::HUD::Stats::LABEL_SIZE,
                                         0));
        newLabelEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::TEXT_PADDING, yOffset}}));
        newLabelEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newLabelEntity));
        statsEntity.emplace(currentId, std::move(newLabelEntity));

        // Value
        increaseId();

        auto newValueEntity = GameEngine::Entity(currentId);
        newValueEntity.addComponent(Text("0",
                                         "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                             std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                             ".ttf",
                                         ConfigClient::HUD::Stats::VALUE_SIZE,
                                         2));
        newValueEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::Stats::WIDTH -
                           ConfigClient::HUD::TEXT_PADDING,
                       yOffset}}));
        newValueEntity.addComponent(Color(ConfigClient::HUD::Stats::VALUE_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newValueEntity));
        statsEntity.emplace(currentId, std::move(newValueEntity));

        yOffset += 40;
    }
}

void HUD::updateStats() {
    GameEngine::System system;
    double             bias = ConfigClient::World::ID +
                  (leaderboardEntities.size() * ConfigClient::Network::ENTITY_LINKING_BIAS);
    auto me = PlayerManagerClient::get().getMe();

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 3;

    system.update(bias,
                  EntityManager::get().entities,
                  GameEngine::UpdateType::Text,
                  std::to_string(me->getScore()));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().entities,
                  GameEngine::UpdateType::Text,
                  std::to_string(me->getMass()));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().entities,
                  GameEngine::UpdateType::Text,
                  std::to_string(NetworkClient::get().getPing()));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().entities,
                  GameEngine::UpdateType::Text,
                  std::to_string(GameClient::get().getFPS()));
}

void HUD::createChatBox() {
    increaseId();

    // Box
    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::ChatBox::WIDTH, ConfigClient::HUD::ChatBox::HEIGHT}));
    newEntity.addComponent(
        Position({{ConfigClient::HUD::PADDING,
                   GameClient::get().getWindowSize().y -
                       (ConfigClient::HUD::ChatBox::HEIGHT + ConfigClient::HUD::PADDING)}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    chatBoxEntitites.emplace(currentId, std::move(newEntity));
}

void HUD::increaseId() {
    currentId += ConfigClient::Network::ENTITY_LINKING_BIAS;
}

void HUD::setMass(long newMass) {}

void HUD::setScore(long newScore) {}