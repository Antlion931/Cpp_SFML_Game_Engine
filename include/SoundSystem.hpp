#pragma once
#include<SFML/Audio.hpp>
#include<map>
#include<deque>
#include<string>

class SoundSystem{
public:
    static SoundSystem* getInstance(std::string directoryPath = "");

    void playSound(std::string soundName);

    void setVolume(std::string soundName, float volume);
    void setMasterVolume(float volume);

    float returnMasterVolume() const;
    
private:
    SoundSystem(std::string directoryPath);
    static SoundSystem* instance;
    float masterVolume = 50.f;
    std::map<std::string, sf::Sound> sounds;
    std::map<std::string, float> volumes;
};