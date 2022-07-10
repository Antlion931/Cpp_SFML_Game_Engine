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
#include "Town.hpp"
#include <memory>
#include "GUI/text.hpp"
#include "Loaders/ResourceLoader.hpp"
#include "Nodes/Grid.hpp"
#include "Standard/CenterString.hpp"
#include "Nodes/smoke.hpp"
#include "GUI/InGameText.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/PlayLevelScene.hpp"

class game : public engine::engineer{
    using animation_map = std::unordered_map<std::string,AtlasManager::animation>;
    public:
    void onStart() override
    {
        TextureLoaderPrototypeFactory::getInstance("res/textures/");
        musicSystem = MusicSystem::getInstance("res/musics/");
        soundSystem = SoundSystem::getInstance("res/sounds/");
        musicSystem->playMusic("winter.wav");
        musicSystem->setVolume("winter.wav", 100.0);
        musicSystem->setRepeat("winter.wav", true);
        //train = Node::create<Train>();
        //animation_map m; m["test"] = {1.f,{0,0},4};
        //atlasManager = new AtlasManager("tilesheet.png",{32,32},m);

        playLevelScene = new PlayLevelScene(window);
        mainMenuScene = new MainMenuScene(&curr_scene, playLevelScene);
        curr_scene = (Scene*)mainMenuScene;

        //grid = Node::create<Grid>(engine::Vec2i(5,5), std::string("tilesheet.png"), engine::Vec2i(32,32));
        //grid->scale({5.f,5.f});
        //grid->loadTileDataFromFile("");
        //grid->setTile({0,0},5);
    }
    void update(const sf::Time& delta) override
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonReleased)
            { 
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(auto v = ColorIDMap::get_instance()->get_color_at({event.mouseButton.x,event.mouseButton.y})){
                        ColorLookup::get_instance()->emit_click(v.value());
                    }
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    is_color_map_visible = !is_color_map_visible;
                    std::cout << is_color_map_visible << std::endl;
                }
                else if(event.key.code == sf::Keyboard::R) {
                    curr_scene = mainMenuScene;
                    delete playLevelScene;
                    playLevelScene = new PlayLevelScene(window);
                    curr_scene = playLevelScene;
                }
                else if(event.key.code == sf::Keyboard::T) {
                    playLevelScene->train->win();
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                //pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
            }
            // else if (event.type == sf::Event::MouseMoved)
            // {
            //     if(auto v = ColorIDMap::get_instance()->get_color_at({event.mouseMove.x,event.mouseMove.y})){
            //             ColorLookup::get_instance()->emit_hover(v.value());
            //     }
            // }
        }


        
        curr_scene->update(delta);
    }
    void draw() override
    {
        curr_scene->draw();
    }
    private:
    float score;
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;

    MainMenuScene* mainMenuScene;
    PlayLevelScene* playLevelScene;

    Scene* curr_scene;
};

int main()
{
    srand(time(NULL));
    game test;
    test.start();
    return 0;
}