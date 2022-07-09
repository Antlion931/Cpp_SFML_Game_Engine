#pragma once
#include "GUI.hpp"
#include "engine.hpp"
#include "Loaders/ResourceLoader.hpp"

namespace engine
{
    class Text : public GUI
    {
    public:
        void set_text(const std::string& _text)
        {
            ResourceLoader* resourceLoader = ResourceLoader::get_instance();
            resourceLoader->load_font("arial.ttf");
            text.setFont(*resourceLoader->get_font(0));
            text.setString(_text);
        }
    private:
        sf::Text text;
    protected:
        virtual void onDraw() const {
            render_layer->draw(text);
        }
        virtual void onUpdate(const sf::Time& delta) {}
    };
}