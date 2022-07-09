#include "Train.hpp"
#include "Layers.hpp"

Train::Train() :  animationManager("train", {{"idle", 1}}, "idle"), body({100.0, 200.0})
{
    body.setOrigin(50.0, 200.0);
    body.setPosition(300.0, 300.0);
}

void Train::onUpdate(const sf::Time& delta)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        angle += 40.0 * delta.asSeconds();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        angle -= 40.0 * delta.asSeconds();
    }

    while(angle >= 180)
    {
        angle -= 360;
    }
    while(angle <= -180)
    {
        angle += 360;
    }

    body.setRotation(-angle);
    body.move({speed * delta.asSeconds() * std::sin(angle / 180.0 * M_PI), speed * delta.asSeconds() * std::cos(angle / 180.0 * M_PI)});
    body.setTexture(animationManager.getTexture().get());
    body.setTextureRect(animationManager.getIntRect());

    if(angle > 0.0)
    {
        animationManager.update(delta, true);
    }
    else
    {
        animationManager.update(delta, false);
    }
}

void Train::onDraw() const
{
    Layers::get_instance()->get_layer(1)->draw(body);
}
