#pragma once
#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include "AnimationManager.hpp"

class SpriteNode : public Node{
public:
    virtual void onCreate()
    {
        if(!shader.loadFromFile("res/shaders/color_id_shader.vert","res/shaders/color_id_shader.frag"))
            std::cout << "Failed to load shaders!\n";
        shader.setParameter("texture", sf::Shader::CurrentTexture);
        shader.setParameter("color_id", color_id);
    }
protected:
    void onDraw() const override
    {
        Layers* layers = Layers::get_instance();
        ColorIDMap::get_instance()->get_color_layer()->draw(sprite, &shader);
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

    sf::Shader shader;
};