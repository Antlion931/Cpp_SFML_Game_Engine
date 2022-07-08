#include <SFML/Graphics.hpp>
#include "Standard/math.hpp"
#include "engine.hpp"
#include "TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
#include "Node.hpp"
#include "Layers.hpp"
#include "GUI/GUI.hpp"

class game : public engine::engine{
    public:
    void onStart() override
    {
        TextureLoaderPrototypeFactory::getInstance("res/textures/");
        //musicSystem = MusicSystem::getInstance();
        //soundSystem = SoundSystem::getInstance();
        testCircle = new TestAnimatedCircle();
    }
    void update(const sf::Time& delta) override
    {
        testCircle->update(delta);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    void draw() override
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(100, 50));
        Layers* layers = Layers::get_instance();
        (*layers)[0]->draw(testCircle->draw());
    }
    private:
    TestAnimatedCircle* testCircle;
    //MusicSystem* musicSystem;
    //SoundSystem* soundSystem;
};

int main()
{
    game test;
    test.start();
    return 0;
}