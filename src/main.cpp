#include <SFML/Graphics.hpp>
#include "Standard/math.hpp"
#include "engine.hpp"
#include "TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
#include "Node.hpp"
#include "Layers.hpp"
#include "GUI/GUI.hpp"

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
        font = new sf::Font();
        font->loadFromFile("res/fonts/arial.ttf");
    }
    void update(const sf::Time& delta) override
    {
        testCircle->update(delta);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        Layers* layers = Layers::get_instance();
        sf::Text text("text", *font);
        text.setPosition(sf::Vector2f(100.f,0.f));
        (*layers)[0]->draw(text);
        (*layers)[1]->draw(testCircle->draw());
    }
    private:
    TestAnimatedCircle* testCircle;
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
    sf::Font* font;
};

int main()
{
    game test;
    test.start();
    return 0;
}