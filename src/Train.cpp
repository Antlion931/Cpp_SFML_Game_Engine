#include "Train.hpp"
#include "Layers.hpp"

const float pi = 3.14159;

Train::Train() :  animationManager("train", {{"idle", 1}}, "idle"), body({40.0, 80.0}),trackModel({12.5, 10.0})
{
    body.setOrigin(20.0, 80.0);
    trackModel.setOrigin(6.25, 10.0);
    body.setPosition(300.0, 300.0);
    trackModel.setPosition(300.0, 300.0);
}

void Train::onReady() {
    track = Node::create<Track>(shared_from_this(),(global_transform.getTransform() * trackModel.getTransform()) * ((trackModel.getPoint(1) + trackModel.getPoint(2))/2.f),(global_transform.getTransform() * trackModel.getTransform()) * ((trackModel.getPoint(3)+trackModel.getPoint(4))/2.f));
    sp = Node::create<SmokeParticles>(shared_from_this());
}

void Train::onUpdate(const sf::Time& delta)
{
    currentTime += delta.asSeconds();

    if(currentTime > tracksMakingTime)
    {
        currentTime -= tracksMakingTime;
        track->add((global_transform.getTransform() * trackModel.getTransform()) * ((trackModel.getPoint(1) + trackModel.getPoint(2))/2.f),(global_transform.getTransform() * trackModel.getTransform()) * ((trackModel.getPoint(3)+trackModel.getPoint(4))/2.f));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        angle += turningRate * delta.asSeconds();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        angle -= turningRate * delta.asSeconds();
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
    trackModel.setRotation(body.getRotation());
    body.move({(float)(speed * delta.asSeconds() * std::sin(angle / 180.0 * pi)), (float)(speed * delta.asSeconds() * std::cos(angle / 180.0 * pi))});
    trackModel.setPosition(body.getPosition());
    body.move({(float)(speed * delta.asSeconds() * std::sin(angle / 180.0 * pi)), (float)(speed * delta.asSeconds() * std::cos(angle / 180.0 * pi))});
    body.setTexture(animationManager.getTexture().get());
    body.setTextureRect(animationManager.getIntRect());
    sp->changeOrigin((global_transform.getTransform() * body.getTransform()) * (body.getPoint(angle > 0.0) + sf::Vector2f{0,10}));

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
