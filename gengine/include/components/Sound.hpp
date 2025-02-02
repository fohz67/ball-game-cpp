#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <utility>
#include "Components.hpp"

class Sound : public Component {
  public:
    // Constants
    static inline std::string DEFAULT_SOUND_FILE = "";

    // Constructor / Destructor
    Sound(const std::string soundFile = DEFAULT_SOUND_FILE);
    Sound(const Sound& other)
        : soundFile(other.soundFile), volume(other.volume),
          buffer(other.buffer), loaded(other.loaded) {
        sound.setBuffer(buffer);
    }
    Sound(Sound&& other) noexcept
        : soundFile(std::move(other.soundFile)), volume(other.volume),
          buffer(std::move(other.buffer)), loaded(other.loaded) {
        sound.setBuffer(buffer);
    }
    ~Sound() = default;

    // Operators
    Sound& operator=(const Sound& other) {
        if (this != &other) {
            soundFile = other.soundFile;
            volume = other.volume;
            buffer = other.buffer;
            loaded = other.loaded;
            sound.setBuffer(buffer);
        }
        return *this;
    }
    Sound& operator=(Sound&& other) noexcept {
        if (this != &other) {
            soundFile = std::move(other.soundFile);
            volume = other.volume;
            buffer = std::move(other.buffer);
            loaded = other.loaded;
            sound.setBuffer(buffer);
        }
        return *this;
    }

    // Singleton
    static Sound& get();

    // Getters
    sf::Sound& getSound();
    sf::SoundBuffer& getSoundBuffer();
    std::string getSoundFile() const;
    int getVolume() const;

    // Setters
    void setSoundFile(const std::string val);
    void setVolumeSound(const int val);

    // Methods
    void display() const override;

  private:
    // Constants
    static constexpr int DEFAULT_VOLUME = 50;
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string soundFile;
    int volume = DEFAULT_VOLUME;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    bool loaded = DEFAULT_LOADED;
};
