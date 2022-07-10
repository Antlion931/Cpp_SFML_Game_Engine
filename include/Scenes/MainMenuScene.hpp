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
        tutorialNotButton = Node::create<Button>(std::string("tutorial.png"));
        playButton->setScale({4.f,4.f});
        playButton->setTranslation({1000.f,20.f});
        tutorialNotButton->setScale({3.2f,3.2f});
        tutorialNotButton->setTranslation({1050.f,270.f});
    }
    virtual void draw() {
        Layers* layers = Layers::get_instance();

        auto spr = sf::Sprite(*animationManager.getTexture());
        spr.setScale({5.7f,5.7f});
        spr.setPosition({0.f,-30.f});
        (*layers)[0]->draw(spr);

        playButton->draw();
        tutorialNotButton->draw();
    }
    virtual void update(const sf::Time& delta) {
        animationManager.update(delta,false);
        playButton->update(delta);
    }
private:
    std::shared_ptr<Button> playButton;
    std::shared_ptr<Button> tutorialNotButton;
    EventListener<> el = EventListener<>([this]() {
        *curr_scene_ptr = playLevelScene;
    });

    PlayLevelScene* playLevelScene;
    Scene** curr_scene_ptr;

    AnimationManager animationManager = AnimationManager("menuArt", {{"idle",2}},"idle");
};