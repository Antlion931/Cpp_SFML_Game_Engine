#include <SFML/Graphics.hpp>
#include "Standard/math.hpp"
#include "engine.hpp"
#include "Loaders/TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
#include "Node.hpp"
#include "Layers.hpp"
#include "Track.hpp"
#include "GUI/GUI.hpp"
#include "test/SpriteNode.hpp"
#include "Standard/line.hpp"
#include "Train.hpp"
#include <memory>
#include "GUI/text.hpp"

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
        spriteNode = Node::create<SpriteNode>();

        train = Node::create<Train>();
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
                //pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
            }
        }
        spriteNode->update(delta);
        train->update(delta);
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        Layers* layers = Layers::get_instance();
        //layers->get_layer(0))->draw(testCircle->draw());
        sf::Text text("text", *ResourceLoader::get_instance()->get_font(0).get());
        text.setPosition(sf::Vector2f(100.f,0.f));
        (*layers)[0]->draw(text);

        spriteNode->draw();
        train->draw();
        auto l = (*layers)[0];
        pl.draw(*l, sf::RenderStates());
        if(colorIDMap->get_hovered_object())
            std::cout << "hover!\n";
        std::shared_ptr<engine::Text> eng_text = engine::Text::create<engine::Text>();
        eng_text->draw();
    }
    private:
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
    std::shared_ptr<Train> train;
    std::shared_ptr<SpriteNode> spriteNode;
    engine::PolyLine pl = engine::PolyLine(sf::Vertex({100,100}, sf::Color(255,0,0,255)), 20); 

};

int main()
{
    game test;
    test.start();
    return 0;
}