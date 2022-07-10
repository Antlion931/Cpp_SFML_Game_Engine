#pragma once
#include <memory>
#include "Scene.hpp"
#include "GUI/button.hpp"

class MainMenuScene : public Scene
{
public:
    MainMenuScene()
    {
        playButton = Node::create<Button>(std::string("play_button.png"));
    }
    virtual void draw() {
        playButton->draw();
    }
    virtual void update(const sf::Time& delta) {

    }
private:
    std::shared_ptr<Button> playButton; 
};