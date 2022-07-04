#include <SFML/Graphics.hpp>
#include "engine.hpp"

class game : public engine::engine{
    public:
    void onStart() override
    {
        circle = new sf::CircleShape(100.f);
        circle->setFillColor(sf::Color::Green);
    }
    void update() override
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
    void draw() override
    {
        window->draw(*circle);
    }
    private:
    sf::CircleShape* circle;
};

int main()
{
    game test;
    test.start();
    return 0;
}