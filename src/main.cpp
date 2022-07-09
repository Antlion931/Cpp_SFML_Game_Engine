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
        track = new Track({100.0, 100.0}, {150.0, 100.0});
        isNewTrackUnderConstruct = false;
        font = new sf::Font();
        font->loadFromFile("res/fonts/arial.ttf");
        spriteNode = Node::create<SpriteNode>();
    }
    void update(const sf::Time& delta) override
    {
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
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
            }
        }
        spriteNode->update(delta);
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        Layers* layers = Layers::get_instance();
        //layers->get_layer(0))->draw(testCircle->draw());
        track->Draw(window);
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
    Track* track; 
    sf::Vector2f newTrack[2];
    bool isNewTrackUnderConstruct;
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