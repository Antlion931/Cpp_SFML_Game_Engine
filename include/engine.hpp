#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Layers.hpp"

namespace engine
{
    class engine
    {
    public:
        engine(unsigned int windowSizeX = 800, unsigned int windowSizeY = 800, const char* windowName = "Gra O_O")
        {
            window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
        }
        ~engine()
        {
            
        }
    public:
        void start()
        {
            layers = Layers::get_instance();
            layers->add_layer(window, "GUI");
            layers->add_layer(window, "Objects");

            sf::Clock deltaClock;

            onStart();

            while(window.isOpen())
            {
                sf::Time delta = deltaClock.restart();
                update(delta);
                window.clear();
                for(auto layer : layers->get_layers())
                {
                    layer->clear(sf::Color(0,0,0,0));
                }

                draw();

                for(auto layer : layers->get_layers())
                {
                    layer->display();
                    window.draw(sf::Sprite(layer->getTexture()));
                }
                window.display();
            }
        }
        virtual void onStart() = 0;
        virtual void update(const sf::Time& delta)  = 0;
        virtual void draw()    = 0;
    protected:
    // glowne okno
        sf::RenderWindow window;
    // wartstwy renderowania
        Layers* layers;
    // config (TO DO)
        std::unordered_map<std::string, sf::Keyboard> KeyBindings;
        std::string lang = "eng";
    };
}