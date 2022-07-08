#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Layers.hpp"
#include "ColorIDMap.hpp"

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
            colorIDMap = ColorIDMap::get_instance();

            layers = Layers::get_instance();
            layers->add_layer(window, "GUI");
            layers->add_layer(window, "Objects");

            sf::Clock deltaClock;

            onStart();

            while(window.isOpen())
            {
                auto layers_vec = layers->get_layers();

                // UPDATE                
                sf::Time delta = deltaClock.restart();
                update(delta);

                // CLEAR THE WINDOW AND ALL LAYERS
                window.clear();
                for(int i = layers_vec.size()-1; i >= 0; i--)
                {
                    layers_vec[i]->clear(sf::Color(0,0,0,0));
                }
                colorIDMap->get_color_layer()->clear(sf::Color(0,0,0,0));

                // DRAW TO ALL LAYERS
                draw();
                for(int i = layers_vec.size()-1; i >= 0; i--)
                {
                    layers_vec[i]->display();
                    window.draw(sf::Sprite(layers_vec[i]->getTexture()));
                }
                // DISPLAY
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
        ColorIDMap* colorIDMap;
    // config (TO DO)
        std::unordered_map<std::string, sf::Keyboard> KeyBindings;
        std::string lang = "eng";
    };
}