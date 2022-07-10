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
    std::vector<std::shared_ptr<Town>> towns;

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

        towns.push_back(Node::create<Town>(center("Warsaw"), true, sf::Vector2f(500.0, 500.0)));
        towns.push_back(Node::create<Town>(center("Berlin"), true, sf::Vector2f(500.0, 600.0)));
        towns.push_back(Node::create<Town>(center("Kiev"), true, sf::Vector2f(500.0, 700.0)));
        towns.push_back(Node::create<Town>(center("Tirana"), false, sf::Vector2f(500.0, 800.0)));
        towns.push_back(Node::create<Town>(center("Bratislava"), false, sf::Vector2f(500.0, 900.0)));
        towns.push_back(Node::create<Town>(center("Vienna"), true, sf::Vector2f(500.0, 1000.0)));
        towns.push_back(Node::create<Town>(center("Minsk"), true, sf::Vector2f(500.0, 1100.0)));
        towns.push_back(Node::create<Town>(center("Vilnius"), false, sf::Vector2f(500.0, 1200.0)));
        towns.push_back(Node::create<Town>(center("Bern"), false, sf::Vector2f(500.0, 1300.0)));
        towns.push_back(Node::create<Town>(center("Riga"), false, sf::Vector2f(500.0, 1400.0)));
        towns.push_back(Node::create<Town>(center("Tallinn"), false, sf::Vector2f(500.0, 1500.0)));
        towns.push_back(Node::create<Town>(center("Rome"), true, sf::Vector2f(500.0, 1600.0)));
        towns.push_back(Node::create<Town>(center("Chisinau"), false, sf::Vector2f(500.0, 1700.0)));
        towns.push_back(Node::create<Town>(center("Ljubljana"), false, sf::Vector2f(500.0, 1800.0)));
        towns.push_back(Node::create<Town>(center("Bucharest"), true, sf::Vector2f(500.0, 1900.0)));
        towns.push_back(Node::create<Town>(center("Budapest"), true, sf::Vector2f(500.0, 2000.0)));
        towns.push_back(Node::create<Town>(center("Prague"), true, sf::Vector2f(500.0, 2100.0)));
        towns.push_back(Node::create<Town>(center("Belgrade"), true, sf::Vector2f(500.0, 2200.0)));
        towns.push_back(Node::create<Town>(center("Zagreb"), false, sf::Vector2f(500.0, 2300.0)));
        towns.push_back(Node::create<Town>(center("Sarajevo"), false, sf::Vector2f(500.0, 2400.0)));
        towns.push_back(Node::create<Town>(center("Sofia"), true, sf::Vector2f(500.0, 2500.0)));
        towns.push_back(Node::create<Town>(center("Skopje"), false, sf::Vector2f(500.0, 2600.0)));
        towns.push_back(Node::create<Town>(center("Tirana"), false, sf::Vector2f(500.0, 2700.0)));
        towns.push_back(Node::create<Town>(center("Podgorica"), false, sf::Vector2f(500.0, 2800.0)));
    }

    virtual void draw() {
        grid->draw();
        train->draw();
        playersScore->draw();
        playersSpeed->draw();
        playersTurnSpeed->draw();
        for(auto t : towns)
        {
            t->draw();
        }
    }
    virtual void update(const sf::Time& delta) {
        grid->update(delta);
        train->update(delta);
        playersScore->update(delta);
        playersSpeed->update(delta);
        playersTurnSpeed->update(delta);
        for(auto t : towns)
        {
            t->update(delta);
        }

        // UPDATE VIEW (CAMERA FOLLOWS PLAYER)
        sf::View new_view = window.getView();
        new_view.setCenter(train->getBodyTranslation());
        auto layers_vec = Layers::get_instance()->get_layers();
        for(int i = layers_vec.size()-1; i > 0; i--)
            layers_vec[i]->setView(new_view);
        ColorIDMap::get_instance()->get_color_layer()->setView(new_view);
    }
};