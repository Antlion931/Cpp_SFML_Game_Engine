#pragma once
#include <memory>
#include "Scene.hpp"
#include "GUI/button.hpp"
#include "PlayLevelScene.hpp"

class MainMenuScene : public Scene
{
public:
    MainMenuScene(Scene** curr_scene_ptr, PlayLevelScene* playLevelScene) : curr_scene_ptr(curr_scene_ptr), playLevelScene(playLevelScene)
    {
        playButton = Node::create<Button>(std::string("play_sign.png"));
        playButton->wire_callback(el);
    }
    virtual void draw() {
        playButton->draw();
    }
    virtual void update(const sf::Time& delta) {

    }
private:
    std::shared_ptr<Button> playButton;
    EventListener<> el = EventListener<>([this]() {
        *curr_scene_ptr = playLevelScene;
    });

    PlayLevelScene* playLevelScene;
    Scene** curr_scene_ptr;

    sf::Sprite background;
};