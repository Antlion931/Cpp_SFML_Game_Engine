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
        musicSystem->setRepeat("winter.wav", true);
        //train = Node::create<Train>();
        //animation_map m; m["test"] = {1.f,{0,0},4};
        //atlasManager = new AtlasManager("tilesheet.png",{32,32},m);

        mainMenuScene = new MainMenuScene();
        playLevelScene = new PlayLevelScene();
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
            if (event.type == sf::Event::MouseButtonPressed)
            { 

            }
            if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    is_color_map_visible = !is_color_map_visible;
                    std::cout << is_color_map_visible << std::endl;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //pl.append_vertex(sf::Vertex({(float)event.mouseButton.x,(float)event.mouseButton.y}, sf::Color(255,0,0,255)));
            }
        }


        // UPDATE VIEW (CAMERA FOLLOWS PLAYER)
        /*sf::View new_view = window.getView();
        new_view.setCenter(train->getBodyTranslation());
        auto layers_vec = Layers::get_instance()->get_layers();
        for(int i = layers_vec.size()-1; i >= 0; i--)
            layers_vec[i]->setView(new_view);
        ColorIDMap::get_instance()->get_color_layer()->setView(new_view);*/
        curr_scene->update(delta);
    }
    void draw() override
    {
        curr_scene->draw();
    }
    private:
    // systems
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;

    MainMenuScene* mainMenuScene;
    PlayLevelScene* playLevelScene;

    Scene* curr_scene;
};

int main()
{
    game test;
    test.start();
    return 0;
}