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
#include "Standard/line.hpp"
#include <memory>

class game : public engine::engineer{
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
        spriteNode = Node::create<SpriteNode>();
        pl.append_vertex(sf::Vertex({100,200}, sf::Color(255,0,0,255)));
        pl.append_vertex(sf::Vertex({150,150}, sf::Color(255,0,0,255)));
        pl.append_vertex(sf::Vertex({250,200}, sf::Color(0,255,0,255)));
        pl.append_vertex(sf::Vertex({300,300}, sf::Color(255,0,0,255)));
        pl.append_vertex(sf::Vertex({355,310}, sf::Color(255,0,255,255)));
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
            if (event.type == sf::Event::MouseButtonPressed) {
                pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
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
        auto l = (*layers)[0];
        pl.draw(*l, sf::RenderStates());
        //if(colorIDMap->get_hovered_object())
           // std::cout << "hover!\n";
    }
    private:
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
    sf::Font* font;

    std::shared_ptr<SpriteNode> spriteNode;
    engine::PolyLine pl = engine::PolyLine(sf::Vertex({100,100}, sf::Color(255,0,0,255)), 20); 

    

};

int main()
{
    game test;
    test.start();
    return 0;
}