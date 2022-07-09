#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Layers.hpp"
#include "ColorIDMap.hpp"
#include "Nodes/Node.hpp"
#include "Loaders/ResourceLoader.hpp"
#include "AtlasManager.hpp"

//#define COLOR_ID_MAP_DEBUG


namespace engine
{
    class engineer
    {
    public:
        engineer(unsigned int windowSizeX = 800, unsigned int windowSizeY = 800, const char* windowName = "Gra O_O")
        {
            window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
        }
        ~engineer()
        {
            
        }
    public:
        void start()
        {
            colorIDMap = ColorIDMap::get_instance();
            colorIDMap->set_window(&window);

            layers = Layers::get_instance();
            layers->add_layer(window, "GUI");
            layers->add_layer(window, "Objects");
            layers->add_layer(window, "Objects 2");
            layers->add_layer(window, "Tilemap");

            ResourceLoader* resourceLoader = ResourceLoader::get_instance();
            resourceLoader->load_font("arial.ttf");
            resourceLoader->load_font("PixelCombat-Wajz.ttf");
            
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
                #ifndef COLOR_ID_MAP_DEBUG
                colorIDMap->get_color_layer()->display();
                for(int i = layers_vec.size()-1; i >= 0; i--)
                {
                    layers_vec[i]->display();
                    window.draw(sf::Sprite(layers_vec[i]->getTexture()));
                }
                #else
                colorIDMap->get_color_layer()->display();
                window.draw(sf::Sprite(colorIDMap->get_color_layer()->getTexture()));
                #endif
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