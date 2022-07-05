#include <SFML/Graphics.hpp>
#include "engine.hpp"

class game : public engine::engine{
    public:
    void onStart() override
    {
        circle = new sf::CircleShape(100.f);
        circle->setFillColor(sf::Color::Green);
    }
    void update(const sf::Time& delta) override
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
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(5);
        rect.setPosition(10, 20);
        GUIRenderLayer.draw(rect);
        ObjectRenderLayer.draw(*circle);
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