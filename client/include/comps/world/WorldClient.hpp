#pragma once

#include <SFML/Graphics.hpp>

class WorldClient {
  public:
    WorldClient(const WorldClient&) = delete;
    WorldClient& operator=(const WorldClient&) = delete;
    static WorldClient& get();
    void init(int width, int height);
    void create(int width, int height);
    void zoom(float factor);
    void render(sf::RenderWindow& window);

  private:
    WorldClient() = default;
    ~WorldClient() = default;
    int width, height;
    float scaleFactor;
    sf::RectangleShape worldRect;
};
