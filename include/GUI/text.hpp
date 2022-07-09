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
    public:
        virtual void onCreate() override {
            auto r = ResourceLoader::get_instance();
            text.setString("basic_text");
            text.setFont(*r->get_font(0).get());
        }
    protected:
        virtual void onDraw() const {
            render_layer->draw(text);
        }
        virtual void onUpdate(const sf::Time& delta) {}
    };
}