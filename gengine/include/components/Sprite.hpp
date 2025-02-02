#pragma once

#include "Components.hpp"
#include "Texture.hpp"
#include <utility>

class Sprite : public Component {
  public:
    // Constants
    static inline std::pair<double, double> DEFAULT_SIZE = {-1, -1};

    // Constructor / Destructor
    Sprite(const std::pair<double, double>& size = DEFAULT_SIZE);
    ~Sprite() = default;

    // Getters
    std::string getTexturePath() const;
    std::pair<double, double> getSize() const;
    bool isLoaded() const;
    sf::Sprite& getSprite();

    // Setters
    void setTexturePath(const std::string& val);
    void setSize(const std::pair<double, double>& val);
    void setLoaded(const bool val);
    void setSprite(const sf::Sprite& val);

    // Methods
    void display() const override;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string texturePath;
    std::pair<double, double> size;
    sf::Sprite sprite;
    bool loaded = DEFAULT_LOADED;
};
