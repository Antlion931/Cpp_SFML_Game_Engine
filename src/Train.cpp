#include "Train.hpp"
#include "Layers.hpp"

const float pi = 3.14159;

Train::Train() :  animationManager("train", {{"idle", 1}}, "idle"), body({100.0, 200.0})
{
    body.setOrigin(50.0, 200.0);
    body.setPosition(300.0, 300.0);
}

void Train::onReady() {
    track = Node::create<Track>(shared_from_this(),(global_transform.getTransform() * body.getTransform()) * ((body.getPoint(1) + body.getPoint(2))/2.f),(global_transform.getTransform() * body.getTransform()) * ((body.getPoint(3)+body.getPoint(4))/2.f));
}

void Train::onUpdate(const sf::Time& delta)
{
    currentTime += delta.asSeconds();

    if(currentTime > tracksMakingTime)
    {
        currentTime -= tracksMakingTime;
        track->add((global_transform.getTransform() * body.getTransform()) * ((body.getPoint(1) + body.getPoint(2))/2.f),(global_transform.getTransform() * body.getTransform()) * ((body.getPoint(3)+body.getPoint(4))/2.f));
    }

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
    body.move({(float)(speed * delta.asSeconds() * std::sin(angle / 180.0 * pi)), (float)(speed * delta.asSeconds() * std::cos(angle / 180.0 * pi))});
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
    Layers::get_instance()->get_layer(1)->draw(body, global_transform.getTransform());
}
