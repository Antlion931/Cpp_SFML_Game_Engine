#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationManager.hpp"

class TestAnimatedCircle
{
public:
    TestAnimatedCircle();
    void update(const sf::Time& delta);
    sf::CircleShape draw();
private:
    sf::CircleShape body;
    AnimationManager animation;
};