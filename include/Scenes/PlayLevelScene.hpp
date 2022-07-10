#pragma once
#include "Scene.hpp"
#include "Town.hpp"
#include "GUI/InGameText.hpp"

class PlayLevelScene : public Scene
{
public:
    std::shared_ptr<Grid> grid;
    std::shared_ptr<Train> train;
    std::shared_ptr<InGameText> playersScore;
    std::shared_ptr<InGameText> playersCities;
    std::shared_ptr<InGameText> playersSpeed;
    std::shared_ptr<InGameText> playersTurnSpeed;
    std::vector<std::shared_ptr<Town>> towns;

    sf::Time elapsed_from_win;

    sf::RenderWindow& window;
public:
    PlayLevelScene(sf::RenderWindow& window) : window(window) {
        grid = Node::create<Grid>(engine::Vec2i(39,44), std::string("tilesheet3.png"), engine::Vec2i(32,32));
        grid->scale({4.f,4.f});
        train = Node::create<Train>(grid->to_world_from_tile({21,22}));
        playersScore = Node::create<InGameText>("Score: ", &train->score, "", true);
        playersCities = Node::create<InGameText>("Connected Cities: ", &train->cities, " / 23", true);
        playersSpeed = Node::create<InGameText>("Speed: ", &train->speed, "", false);
        playersTurnSpeed = Node::create<InGameText>("Turning Speed: ", &train->turningRate, "", true);

        playersScore->setTranslation({30.0, 30.0});
        playersCities->setTranslation({30.0, 60.0});
        playersSpeed->setTranslation({30.0, 90.0});
        playersTurnSpeed->setTranslation({30.0, 120.0});

        towns.push_back(Node::create<Town>(center("Warsaw"), true, grid->to_world_from_tile({17,18})));
        towns.push_back(Node::create<Town>(center("Berlin"), true, grid->to_world_from_tile({12,18})));
        towns.push_back(Node::create<Town>(center("Kiev"), true, grid->to_world_from_tile({24,22})));
        towns.push_back(Node::create<Town>(center("Tirana"), false, grid->to_world_from_tile({16,35})));
        towns.push_back(Node::create<Town>(center("Bratislava"), false, grid->to_world_from_tile({14,25})));
        towns.push_back(Node::create<Town>(center("Vienna"), true, grid->to_world_from_tile({13,25})));
        towns.push_back(Node::create<Town>(center("Minsk"), true, grid->to_world_from_tile({22,16})));
        towns.push_back(Node::create<Town>(center("Vilnius"), false, grid->to_world_from_tile({20,14})));
        towns.push_back(Node::create<Town>(center("Bern"), false, grid->to_world_from_tile({7,27})));
        towns.push_back(Node::create<Town>(center("Riga"), false, grid->to_world_from_tile({20,10})));
        towns.push_back(Node::create<Town>(center("Tallinn"), false, grid->to_world_from_tile({20,6})));
        towns.push_back(Node::create<Town>(center("Rome"), true, grid->to_world_from_tile({11,34})));
        towns.push_back(Node::create<Town>(center("Chisinau"), false, grid->to_world_from_tile({22,27})));
        towns.push_back(Node::create<Town>(center("Ljubljana"), false, grid->to_world_from_tile({13,28})));
        towns.push_back(Node::create<Town>(center("Bucharest"), true, grid->to_world_from_tile({20,31})));
        towns.push_back(Node::create<Town>(center("Budapest"), true, grid->to_world_from_tile({16,26})));
        towns.push_back(Node::create<Town>(center("Prague"), true, grid->to_world_from_tile({13,22})));
        towns.push_back(Node::create<Town>(center("Belgrade"), true, grid->to_world_from_tile({17,30})));
        towns.push_back(Node::create<Town>(center("Zagreb"), false, grid->to_world_from_tile({14,29})));
        towns.push_back(Node::create<Town>(center("Sarajevo"), false, grid->to_world_from_tile({15,31})));
        towns.push_back(Node::create<Town>(center("Sofia"), true, grid->to_world_from_tile({19,33})));
        towns.push_back(Node::create<Town>(center("Skopje"), false, grid->to_world_from_tile({18,34})));
        towns.push_back(Node::create<Town>(center("Tirana"), false, grid->to_world_from_tile({16,35})));
        towns.push_back(Node::create<Town>(center("Podgorica"), false, grid->to_world_from_tile({16,33})));
    }

    virtual void draw() {
        grid->draw();
        train->draw();
        playersScore->draw();
        playersCities->draw();
        playersSpeed->draw();
        playersTurnSpeed->draw();
        for(auto t : towns)
        {
            t->draw();
        }
    }
    virtual void update(const sf::Time& delta) {
        train->update(delta);
        train->score += 10 * grid->change_nearby_points(train->getBodyFrontTranslation(), 100);
        grid->update(delta);
        playersScore->update(delta);
        playersCities->update(delta);
        playersSpeed->update(delta);
        playersTurnSpeed->update(delta);
        for(auto t : towns)
        {
            t->update(delta);
        }


        // UPDATE VIEW (CAMERA FOLLOWS PLAYER)
        engine::Vec2f goal = grid->to_world_from_tile({19,21});
        sf::View new_view = window.getView();
        if(train->won) {
            elapsed_from_win += delta;
            float new_size_x = std::min(new_view.getSize().x * (1 + 0.2f*elapsed_from_win.asSeconds()), 1600.f * 3.05f); 
            float new_size_y = std::min(new_view.getSize().y * (1 + 0.2f*elapsed_from_win.asSeconds()), 900.f * 3.05f);
            grid->change_nearby_points(train->getBodyBackTranslation(), 200.f*elapsed_from_win.asSeconds());
            new_view.setSize(new_size_x, new_size_y);
        }
        new_view.setCenter(engine::Vec2f(train->getBodyBackTranslation()) + (goal - engine::Vec2f(train->getBodyBackTranslation())).interpolate(std::min(elapsed_from_win.asSeconds()/2.f,1.f)));
        auto layers_vec = Layers::get_instance()->get_layers();
        for(int i = layers_vec.size()-1; i > 0; i--)
            layers_vec[i]->setView(new_view);
        ColorIDMap::get_instance()->get_color_layer()->setView(new_view);
    }
};