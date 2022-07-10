#pragma once
#include "Nodes/Node.hpp"
#include "Track.hpp"
#include "AnimationManager.hpp"
#include "Nodes/smoke.hpp"

class Train : public Node
{
public:
    Train();
    bool check_collision(engine::Vec2f v);
    void onUpdate(const sf::Time& delta);
    void onDraw() const;
    void onReady();

    sf::Vector2f getBodyFrontTranslation(){ return (global_transform.getTransform() * body.getTransform()) * ((body.getPoint(0) + body.getPoint(1))/2.f); }
    sf::Vector2f getBodyBackTranslation(){ return body.getPosition(); }

    float turningRate = 90.0;
    float speed = 200.0f;
private:
    float currentTime = 0.0;
    float tracksMakingTime = 14;
    float angle = 0.0f;
    std::shared_ptr<Track> track;
    AnimationManager animationManager;
    sf::RectangleShape body;
    sf::RectangleShape trackModel;
    std::shared_ptr<SmokeParticles> sp;
};
