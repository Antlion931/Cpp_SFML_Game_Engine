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
    }

    void wire_callback(EventListener<> listener) {
        ColorLookup::get_instance()->register_click(color_id, listener);
    }

    virtual void onReady() override {
        ColorLookup::get_instance()->register_hover(color_id, hover_el);
    }

protected:
    virtual void onDraw() const {
        render_layer->draw(texture, global_transform.getTransform());
        auto shader = ColorIDMap::color_id_shader;
        shader->setUniform("color_id", sf::Glsl::Vec4(color_id));
        sf::RenderStates rs;
        rs.shader = shader; rs.transform = global_transform.getTransform();
        ColorIDMap::get_instance()->get_color_layer()->draw(texture,rs);
    }
    virtual void onUpdate(const sf::Time& delta) {  
        
    }
private:
    sf::Sprite texture;
    bool hovered = false;
    
    EventListener<> hover_el = EventListener<>([this]() {
        hovered = true;
    });

};


