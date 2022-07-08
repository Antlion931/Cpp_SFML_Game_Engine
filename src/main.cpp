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
#include "test/SpriteNode.hpp"
#include <memory>

class game : public engine::engine{
    public:
    void onStart() override
    {
        TextureLoaderPrototypeFactory::getInstance("res/textures/");
        musicSystem = MusicSystem::getInstance("res/musics/");
        soundSystem = SoundSystem::getInstance("res/sounds/");
        musicSystem->playMusic("GamePlayMusic.wav");
        soundSystem->playSound("dead.wav");
        soundSystem->setVolume("dead.wav", 100.0f);
        soundSystem->playSound("punch.wav");
        font = new sf::Font();
        font->loadFromFile("res/fonts/arial.ttf");
        spriteNode = std::make_shared<SpriteNode>();
    }
    void update(const sf::Time& delta) override
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                
            }
        }
        spriteNode->update(delta);
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        sf::Text text("text", *font);
        text.setPosition(sf::Vector2f(100.f,0.f));
        (*layers)[0]->draw(text);

        spriteNode->draw();
        if(colorIDMap->get_hovered_object())
            std::cout << "hover!\n";
    }
    private:
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
    sf::Font* font;

    std::shared_ptr<SpriteNode> spriteNode;

};

int main()
{
    game test;
    test.start();
    return 0;
}