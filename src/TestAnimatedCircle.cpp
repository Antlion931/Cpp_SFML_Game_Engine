#include "TestAnimatedCircle.hpp"

TestAnimatedCircle::TestAnimatedCircle() : body(100.f), animation("test", {{"run", 2}}, "run")
{}

void TestAnimatedCircle::update(const sf::Time& delta)
{
    animation.play("run");
    animation.update(delta, true);
}

sf::CircleShape TestAnimatedCircle::draw()
{
    body.setTexture(animation.getTexture().get());
    body.setTextureRect(animation.getIntRect());
    return body;
}
