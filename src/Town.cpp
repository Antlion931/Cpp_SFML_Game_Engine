#include "Town.hpp"

Town::Town(std::string _name, bool isItBig, sf::Vector2f position) : animationManager((isItBig ? "bigTown" : "smallTown"), {{"dead", 2}, {"idle", 14.5 }}, "dead"), body({100, 100})
{
    name = _name;
    body.setPosition(position);
}

void Town::Repair()
{
    animationManager.setDefault("idle");
    animationManager.play("idle");
}

void Town::onReady()
{
    text = engine::Text::create<engine::Text>(shared_from_this());
    sf::Vector2f newTextPosition = body.getPosition();
    newTextPosition.y -= body.getSize().y / 5.0;
    text->setTranslation(newTextPosition);
    text->setLayer(1);
    text->set_text(name);
}

void Town::onUpdate(const sf::Time& delta)
{
    animationManager.update(delta, false);
    body.setTexture(animationManager.getTexture().get());
    body.setTextureRect(animationManager.getIntRect());
}

void Town::onDraw() const
{
     Layers::get_instance()->get_layer(1)->draw(body, global_transform.getTransform());
}
    