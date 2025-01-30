/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Sound.hpp
*/

#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include "Components.hpp"

class Sound : public Component {
  public:
    Sound(std::string soundFile = "");
    Sound(const Sound& other) 
    : _soundFile(other._soundFile), 
      _volume(other._volume), 
      _buffer(other._buffer), 
      _isLoad(other._isLoad) 
    {
        _sound.setBuffer(_buffer);
    }

    Sound& operator=(const Sound& other) {
        if (this != &other) {
            _soundFile = other._soundFile;
            _volume = other._volume;
            _buffer = other._buffer;
            _isLoad = other._isLoad;
            _sound.setBuffer(_buffer);
        }
        return *this;
    }
    Sound(Sound&& other) noexcept 
        : _soundFile(std::move(other._soundFile)),
          _volume(other._volume),
          _buffer(std::move(other._buffer)),
          _isLoad(other._isLoad) 
    {
        _sound.setBuffer(_buffer);
    }

    Sound& operator=(Sound&& other) noexcept {
        if (this != &other) {
            _soundFile = std::move(other._soundFile);
            _volume = other._volume;
            _buffer = std::move(other._buffer);
            _isLoad = other._isLoad;
            _sound.setBuffer(_buffer);
        }
        return *this;
    }

    
    ~Sound();
    static Sound& get();
    sf::Sound& getSound();
    sf::SoundBuffer& getSoundBuffer();
    std::string getSoundFile() const;
    void setSoundFile(std::string soundFile);
    int getVolume() const;
    void setVolumeSound(int volume);
    void display() const override;

  private:
    std::string _soundFile;
    int _volume = 50;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
    bool _isLoad = false;
};
