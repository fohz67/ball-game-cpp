#include "components/Sound.hpp"

#include <iostream>

Sound::Sound(std::string soundFile) : soundFile(soundFile)
{
}

Sound& Sound::get()
{
    static Sound instance;
    return instance;
}

sf::Sound& Sound::getSound()
{
    return this->sound;
}

sf::SoundBuffer& Sound::getSoundBuffer()
{
    return this->buffer;
}

int Sound::getVolume() const
{
    return this->volume;
}

std::string Sound::getSoundFile() const
{
    return this->soundFile;
}

void Sound::setSoundFile(const std::string val)
{
    this->soundFile = val;
}

void Sound::setVolumeSound(const int val)
{
    this->volume = val;
    sound.setVolume(volume);
}

void Sound::display() const
{
    std::cout << "Sound component displayed!" << std::endl;
}
