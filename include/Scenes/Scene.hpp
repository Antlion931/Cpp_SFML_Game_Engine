#pragma once

class Scene
{
public:
    virtual void draw() {}
    virtual void update(const sf::Time& delta) {}
};