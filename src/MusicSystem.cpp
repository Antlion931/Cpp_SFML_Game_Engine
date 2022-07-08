#include"MusicSystem.hpp"
#include<iostream>
#include <assert.h>
#include<filesystem>

MusicSystem* MusicSystem::instance = nullptr;

MusicSystem::MusicSystem(std::string directoryPath)
{
    for(const auto &entry: std::filesystem::directory_iterator(directoryPath))
    {
        sf::Music* music = new sf::Music;
        if(!music->openFromFile(entry.path().string()))
        {
            std::cerr<<"Error while loading audio!"<<std::endl;
            continue;
        };
        std::string trackName = entry.path().string();
        trackName.erase(0,directoryPath.length());
        musics[trackName] = music;
        volumes[trackName] = 50.0f;
        musics[trackName]->setVolume(volumes[trackName] * masterVolume / 100.0);
    }
}

void MusicSystem::setVolume(std::string trackName, float volume)
{
    volume = std::max(0.0f, volume);
    volume = std::min(100.0f, volume);
    volumes[trackName] = volume;
    musics[trackName]->setVolume(volumes[trackName] * masterVolume / 100.0);

}

void MusicSystem::playMusic(std::string trackName)
{
    musics[trackName]->play();
}

float MusicSystem::returnMasterVolume() const
{
    return masterVolume;
}

void MusicSystem::stopMusic(std::string trackName)
{
    musics[trackName]->stop();
}

void MusicSystem::setRepeat(std::string trackName, bool repeat)
{
    musics[trackName]->setLoop(repeat);
}

MusicSystem* MusicSystem::getInstance(std::string directoryPath)
{
    if(instance == nullptr)
    {
        assert(directoryPath != "");
        instance = new MusicSystem(directoryPath);
    }

    return instance;
}

void MusicSystem::setMasterVolume(float volume)
{
    volume = std::max(0.0f, volume);
    volume = std::min(100.0f, volume);
    masterVolume = volume;
    for(auto[trackName, sfMusic] : musics)
    {
        sfMusic->setVolume(volumes[trackName] * masterVolume / 100.0);
    }
}
