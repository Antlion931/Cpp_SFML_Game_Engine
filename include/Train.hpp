#pragma once
#include "Nodes/Node.hpp"
#include "Track.hpp"
#include "AnimationManager.hpp"
#include "Nodes/smoke.hpp"

class Train : public Node
{
public:
    Train();
    void onUpdate(const sf::Time& delta);
    void onDraw() const;
    void onReady();

    sf::Vector2f getBodyTranslation(){ return body.getPosition(); }

private:
    float currentTime = 0.0;
    float tracksMakingTime = 0.07;
    float turningRate = 90.0;
    float speed = -120.0f;
    float angle = 0.0f;
    std::shared_ptr<Track> track;
    AnimationManager animationManager;
    sf::RectangleShape body;
    sf::RectangleShape trackModel;
    std::shared_ptr<SmokeParticles> sp;
};
