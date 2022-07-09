#include <SFML/Graphics.hpp>
#include "Standard/math.hpp"
#include "engine.hpp"
#include "TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
#include "Node.hpp"
#include "Layers.hpp"
#include "Track.hpp"

class game : public engine::engine{
    public:
    void onStart() override
    {
        TextureLoaderPrototypeFactory::getInstance("res/textures/");
        musicSystem = MusicSystem::getInstance("res/musics/");
        soundSystem = SoundSystem::getInstance("res/sounds/");
        testCircle = new TestAnimatedCircle();
        musicSystem->playMusic("GamePlayMusic.wav");
        soundSystem->playSound("dead.wav");
        soundSystem->setVolume("dead.wav", 100.0f);
        soundSystem->playSound("punch.wav");
        track = new Track({100.0, 100.0}, {150.0, 100.0});
        isNewTrackUnderConstruct = false;
    }
    void update(const sf::Time& delta) override
    {
        testCircle->update(delta);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            { 
                if(!isNewTrackUnderConstruct)
                {
                    newTrack[0].x = sf::Mouse::getPosition(window).x;
                    newTrack[0].y = sf::Mouse::getPosition(window).y;
                    isNewTrackUnderConstruct = true;
                }
                else
                {
                    newTrack[1].x = sf::Mouse::getPosition(window).x;
                    newTrack[1].y = sf::Mouse::getPosition(window).y;
                    isNewTrackUnderConstruct = false;
                    track->add(newTrack[0], newTrack[1]);
                }
            }
            
        }
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        Layers* layers = Layers::get_instance();
        //layers->get_layer(0))->draw(testCircle->draw());
        track->Draw(window);
    }
    private:
    TestAnimatedCircle* testCircle;
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
    Track* track; 
    sf::Vector2f newTrack[2];
    bool isNewTrackUnderConstruct;
};

int main()
{
    game test;
    test.start();
    return 0;
}