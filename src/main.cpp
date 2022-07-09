#include <SFML/Graphics.hpp>
#include "Standard/math.hpp"
#include "engine.hpp"
#include "Loaders/TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
#include "Nodes/Node.hpp"
#include "Layers.hpp"
#include "Track.hpp"
#include "GUI/GUI.hpp"
#include "test/SpriteNode.hpp"
#include "Standard/line.hpp"
#include "Train.hpp"
#include <memory>
#include "GUI/text.hpp"
#include "Loaders/ResourceLoader.hpp"
#include "Nodes/Grid.hpp"

class game : public engine::engineer{
    using animation_map = std::unordered_map<std::string,AtlasManager::animation>;
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
        animation_map m;
        m["test"] = {1.f,{0,0},4};
        atlasManager = new AtlasManager("indoors.png",{16,16},m);

        grid = Node::create<Grid>(engine::Vec2i(5,5), std::string("indoors.png"), engine::Vec2i(16,16));
        grid->scale({5.f,5.f});
        grid->loadTileDataFromFile("");
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

            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
            }
        }
        atlasManager->update(delta);
    }
    void draw() override
    {
        /*sf::VertexArray triangle(sf::Quads, 4);
        // 35 x 30
        // define the position of the triangle's points
        sf::Vector2f a(10.f, 10.f), b(200.f, 10.f), c(200.f, 200.f), d(10.f, 200.f);

        triangle[0].position = a;
        triangle[1].position = b;
        triangle[2].position = c;
        triangle[3].position = d;

        // define the color of the triangle's points
        auto[x,y,z,w] = atlasManager->get_texture_coords_at(atlasManager->get_frame("test"));
        triangle[0].texCoords = x;
        triangle[1].texCoords = y;
        triangle[2].texCoords = z;
        triangle[3].texCoords = w;

        sf::RenderStates state;

        state.texture = atlasManager->get_texture().get();

        (*layers)[1]->draw(triangle,state);*/
        std::shared_ptr<engine::Text> text = engine::Text::create<engine::Text>();
        text->set_text("dwajio");
        text->draw();
        //grid->draw();
        //(*layers)[1]->draw(triangle);
        

    }
    private:
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;  
    AtlasManager* atlasManager;
    std::shared_ptr<Grid> grid;
};

int main()
{
    game test;
    test.start();
    return 0;
}