#include <string>
#include <SFML/Graphics.hpp>

namespace engine
{
    class engine
    {
    public:
        engine(const char* windowName = "Gra O_O", unsigned int windowSizeX = 800, unsigned int windowSizeY = 800)
        {
            window = new sf::RenderWindow(sf::VideoMode(windowSizeX, windowSizeY), windowName);
        }
        ~engine()
        {
            delete window;
        }
    public:
        void start()
        {
            onStart();
            while(window->isOpen())
            {
                update();
                window->clear();
                draw();
                window->display();
            }
        }
        virtual void onStart() = 0;
        virtual void update()  = 0;
        virtual void draw()    = 0;
    protected:
        sf::RenderWindow* window;
    };
}