#pragma once

#include <utility>

#include "components/Components.hpp"
#include "components/Point.hpp"
#include "components/Texture.hpp"

class Sprite : public Component
{
   public:
    // Constants
    static inline Point DEFAULT_SIZE = {-1, -1};

    // Constructor / Destructor
    Sprite(const Point& size = DEFAULT_SIZE);
    ~Sprite() = default;

    // Getters
    std::string getTexturePath() const;
    Point getSize() const;
    bool isLoaded() const;
    sf::Sprite& getSprite();

    // Setters
    void setTexturePath(const std::string& val);
    void setSize(const Point& val);
    void setLoaded(const bool val);
    void setSprite(const sf::Sprite& val);

    // Methods
    void display() const override;

   private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string texturePath;
    Point size;
    sf::Sprite sprite;
    bool loaded = DEFAULT_LOADED;
};
