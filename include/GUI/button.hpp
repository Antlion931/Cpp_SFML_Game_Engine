#pragma once
#include "GUI.hpp"
#include "Standard/Events/event_emitter.hpp"
#include "AnimationManager.hpp"
#include "Loaders/ResourceLoader.hpp"
#include "ColorLookup.hpp"

class Button : public GUI
{
public:
    Button(std::string name)
    {
        ResourceLoader* resourceLoader = ResourceLoader::get_instance();
        resourceLoader->load_texture("res/textures/GUI/"+name);
        texture = sf::Sprite(*(resourceLoader->get_texture(name)));
        texture.setScale({3.5f,3.5f});
    }

    void wire_callback(EventListener<> listener) {
        ColorLookup::get_instance()->register_click(color_id, listener);
    }

protected:
    virtual void onDraw() const {
        render_layer->draw(texture);
        auto shader = ColorIDMap::color_id_shader;
        shader->setUniform("color_id", sf::Glsl::Vec4(color_id));
        ColorIDMap::get_instance()->get_color_layer()->draw(texture, shader);
    }
    virtual void onUpdate(const sf::Time& delta) {
        
    }
private:
    sf::Sprite texture;
};


