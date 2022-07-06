#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace engine
{
    class engine
    {
    public:
        engine(const char* windowName = "Gra O_O", unsigned int windowSizeX = 800, unsigned int windowSizeY = 800)
        {
            window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
        }
        ~engine()
        {

        }
    public:
        void start()
        {
            onStart();
            ObjectRenderLayer.create(window.getSize().x,window.getSize().y);
            GUIRenderLayer.create(window.getSize().x,window.getSize().y);
            sf::Clock deltaClock;
            while(window.isOpen())
            {
                sf::Time delta = deltaClock.restart();
                update(delta);
                window.clear();
<<<<<<< HEAD
                ObjectRenderLayer.clear(sf::Color(0,0,0,0));
                GUIRenderLayer.clear(sf::Color(0,0,0,0));
=======
                ObjectRenderLayer.clear();
                GUIRenderLayer.clear();
>>>>>>> ff14bcc (merge)
                draw();

                ObjectRenderLayer.display();
                GUIRenderLayer.display();
                sf::Sprite GUI(GUIRenderLayer.getTexture());
                sf::Sprite Objects(ObjectRenderLayer.getTexture());

                window.draw(Objects);
                window.draw(GUI);
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
        sf::RenderTexture GUIRenderLayer;
        sf::RenderTexture ObjectRenderLayer;
    };
}