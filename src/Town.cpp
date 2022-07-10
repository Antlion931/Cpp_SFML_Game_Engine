#include "Town.hpp"
#include "SoundSystem.hpp"
#include "ColorLookup.hpp"

Town::Town(std::string _name, bool isItBig, sf::Vector2f position) : animationManager((isItBig ? "bigTown" : "smallTown"), {{"dead", 2}, {"idle", 14.5 }}, "dead"), body({80, 80})
{
    name = _name;
    body.setOrigin(40, 40);
    body.setPosition(position);
}

void Town::Repair()
{
    animationManager.setDefault("idle");
    animationManager.play("idle");
    SoundSystem::getInstance()->playSound("powerUp.wav");
}

void Town::onReady()
{
    text = engine::Text::create<engine::Text>(shared_from_this());
    sf::Vector2f newTextPosition = body.getPosition();
    newTextPosition.y -= body.getSize().y / 5.0 + 45;
    newTextPosition.x -= 70;
    text->setTranslation(newTextPosition);
    text->setLayer(1);
    text->set_text(name);
    ColorLookup::get_instance()->register_train_hit(color_id,el_train);
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
    
    auto shader = ColorIDMap::color_id_shader;
    shader->setUniform("color_id", sf::Glsl::Vec4(color_id));
    sf::RenderStates rs;
    rs.shader = shader; rs.transform = global_transform.getTransform();
    ColorIDMap::get_instance()->get_color_layer()->draw(body,rs);

}
    