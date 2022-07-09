#pragma once
#include "GUI.hpp"
#include "engine.hpp"
#include "ResourceLoader.hpp"

namespace engine
{

    class Text : public GUI
    {
    public:
        void set_text(const std::string& _text)
        {
            text.setString(_text);
        }
    private:
        sf::Text text;
    protected:
        /*virtual void onCreate() {
            auto r = ResourceLoader::get_instance();
            text.setString("text");
            text.setFont(*r->get_font(0).get());
        }*/
        virtual void onDraw() const {
            render_layer->draw(text);
        }
        virtual void onUpdate(const sf::Time& delta) {}
    };
}