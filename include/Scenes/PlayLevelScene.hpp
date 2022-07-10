#pragma once
#include "Scene.hpp"

class PlayLevelScene : public Scene
{

    std::shared_ptr<Grid> grid;
    std::shared_ptr<Train> train;

    sf::RenderWindow& window;
public:
    PlayLevelScene(sf::RenderWindow& window) : window(window) {
        grid = Node::create<Grid>(engine::Vec2i(34,33), std::string("tilesheet.png"), engine::Vec2i(32,32));
        grid->scale({5.f,5.f});
        train = Node::create<Train>();
    }

    virtual void draw() {
        grid->draw();
        train->draw();
    }
    virtual void update(const sf::Time& delta) {
        grid->update(delta);
        train->update(delta);

        // UPDATE VIEW (CAMERA FOLLOWS PLAYER)
        sf::View new_view = window.getView();
        new_view.setCenter(train->getBodyTranslation());
        auto layers_vec = Layers::get_instance()->get_layers();
        for(int i = layers_vec.size()-1; i >= 0; i--)
            layers_vec[i]->setView(new_view);
        ColorIDMap::get_instance()->get_color_layer()->setView(new_view);
    }
};