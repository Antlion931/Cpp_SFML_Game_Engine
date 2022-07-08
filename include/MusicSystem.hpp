#pragma once
#include<SFML/Audio.hpp>
#include<map>
#include<string>

class MusicSystem{
public:
    static MusicSystem* getInstance(std::string directoryPath = "");

    void setVolume(std::string trackName,float volume);
    void setMasterVolume(float volume);
    float returnMasterVolume() const;

    void setRepeat(std::string trackName, bool repeat);

    void stopMusic(std::string trackName);
    void playMusic(std::string trackName);

private:
    MusicSystem(std::string directoryPath);
    static MusicSystem* instance;

    std::map<std::string, sf::Music*> musics;
    std::map<std::string, float> volumes;
    float masterVolume = 100;
};