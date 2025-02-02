#pragma once

#include "Components.hpp"
#include <utility>
#include <vector>
#include <string>

class Texture : public Component {
  public:
    // Constants
    static inline std::string DEFAULT_TEXTURE_PATH = "";
    static inline std::vector<int> DEFAULT_TEXTURE_RECT = {};

    // Constructor / Destructor
    Texture(const std::string& texturePath = DEFAULT_TEXTURE_PATH,
            const std::vector<int>& textureRect = DEFAULT_TEXTURE_RECT);
    ~Texture() = default;

    // Getters
    std::string getTexturePath() const;
    bool isLoaded() const;
    sf::Texture& getTexture();
    std::vector<int> getTextureRect() const;

    // Setters
    void setTexturePath(const std::string& val);
    void setLoaded(bool val);
    void setTexture(const sf::Texture& val);

    // Methods
    void display() const override;

  protected:
  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string texturePath;
    std::vector<int> textureRect;
    sf::Texture texture;
    bool loaded = DEFAULT_LOADED;
};
