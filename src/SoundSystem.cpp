#include "SoundSystem.hpp"
#include <iostream>
#include <assert.h>
#include <filesystem>
#include <math.h>

SoundSystem* SoundSystem::instance = nullptr;

SoundSystem::SoundSystem(std::string directoryPath)
{
    for(const auto &entry: std::filesystem::directory_iterator(directoryPath))
    {
        sf::SoundBuffer* sb = new sf::SoundBuffer();
        if(!sb->loadFromFile(entry.path().string()))
        {
            std::cerr<<"Error while loading audio!"<<std::endl;
            continue;
        };
        std::string soundName = entry.path().string();
        soundName.erase(0,directoryPath.length());
        sounds[soundName] = sf::Sound(*sb);
        volumes[soundName]  = 50.0;
        sounds[soundName].setVolume(volumes[soundName] * masterVolume / 100.0);
        std::cout << sounds[soundName].getBuffer() << std::endl;
    }
}

void SoundSystem::playSound(std::string trackName)
{
    sounds[trackName].play();
}

void SoundSystem::setVolume(std::string soundName, float volume)
{
    volume = std::max(0.0f, volume);
    volume = std::min(100.0f, volume);
    volumes[soundName] = volume;
    sounds[soundName].setVolume(volumes[soundName] * masterVolume / 100.0);
}

void SoundSystem::setMasterVolume(float volume)
{
    volume = std::max(0.0f, volume);
    volume = std::min(100.0f, volume);
    masterVolume = volume;
    for(auto[soundName, sfSound] : sounds)
    {
        sfSound.setVolume(volumes[soundName] * masterVolume / 100.0);
    }
}

float SoundSystem::returnMasterVolume() const
{
    return masterVolume;
}

SoundSystem* SoundSystem::getInstance(std::string directoryPath)
{
    if(instance == nullptr)
    {
        assert(directoryPath != "");
        instance = new SoundSystem(directoryPath);
    }
    return instance;
}
