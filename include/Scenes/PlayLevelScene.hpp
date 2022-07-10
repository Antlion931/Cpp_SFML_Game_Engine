#pragma once
#include "Scene.hpp"
#include "Town.hpp"
#include "GUI/InGameText.hpp"

class PlayLevelScene : public Scene
{
    float score;
    std::shared_ptr<Grid> grid;
    std::shared_ptr<Train> train;
    std::shared_ptr<InGameText> playersScore;
    std::shared_ptr<InGameText> playersSpeed;
    std::shared_ptr<InGameText> playersTurnSpeed;
    std::shared_ptr<Town> warszawa;

    sf::RenderWindow& window;
public:
    PlayLevelScene(sf::RenderWindow& window) : window(window) {
        grid = Node::create<Grid>(engine::Vec2i(34,33), std::string("tilesheet3.png"), engine::Vec2i(32,32));
        grid->scale({4.f,4.f});
        train = Node::create<Train>();
        playersScore = Node::create<InGameText>("Score: ", &score, " %", true);
        playersSpeed = Node::create<InGameText>("Speed: ", &train->speed, "", false);
        playersTurnSpeed = Node::create<InGameText>("TurningSpeed: ", &train->turningRate, "", true);

        playersScore->setTranslation({30.0, 30.0});
        playersSpeed->setTranslation({30.0, 60.0});
        playersTurnSpeed->setTranslation({30.0, 90.0});

        warszawa = Node::create<Town>(center("WARSZAWA"), true, sf::Vector2f(100.0, 100.0));
    }

    virtual void draw() {
        grid->draw();
        train->draw();
        playersScore->draw();
        playersSpeed->draw();
        playersTurnSpeed->draw();
        warszawa->draw();
    }
    virtual void update(const sf::Time& delta) {
        grid->update(delta);
        train->update(delta);
        playersScore->update(delta);
        playersSpeed->update(delta);
        playersTurnSpeed->update(delta);
        warszawa->update(delta);

        // UPDATE VIEW (CAMERA FOLLOWS PLAYER)
        sf::View new_view = window.getView();
        new_view.setCenter(train->getBodyTranslation());
        auto layers_vec = Layers::get_instance()->get_layers();
        for(int i = layers_vec.size()-1; i > 0; i--)
            layers_vec[i]->setView(new_view);
        ColorIDMap::get_instance()->get_color_layer()->setView(new_view);
    }
};