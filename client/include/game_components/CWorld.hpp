#pragma once

#include <SFML/Graphics.hpp>

class CWorld {
  public:
    CWorld(const CWorld&) = delete;
    CWorld& operator=(const CWorld&) = delete;
    static CWorld& get();
    void init(int width, int height);
    void zoom(float factor);
    void render(sf::RenderWindow& window);

  private:
    CWorld() = default;
    ~CWorld() = default;
    int width, height;
    float scaleFactor;
    sf::RectangleShape worldRect;
};
