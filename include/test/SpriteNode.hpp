#pragma once
#include "Nodes/Node.hpp"
#include <SFML/Graphics.hpp>
#include "AnimationManager.hpp"

class SpriteNode : public Node{
public:
    SpriteNode()
    {

    }
protected:
    void onDraw() const override
    {
        Layers* layers = Layers::get_instance();
        auto shader = ColorIDMap::color_id_shader;
        shader->setUniform("color_id", sf::Glsl::Vec4(color_id));
        ColorIDMap::get_instance()->get_color_layer()->draw(sprite, shader);
        (*layers)[1]->draw(sprite);
    }
    void onUpdate(const sf::Time& delta) override
    {
        animationManager.update(delta, false);

        sprite.setTexture(*animationManager.getTexture().get());
        sprite.setTextureRect(animationManager.getIntRect());
    }
private:
    AnimationManager animationManager = AnimationManager("test", {{"run",1}},"run");
    sf::Sprite sprite;
};