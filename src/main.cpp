#include <SFML/Graphics.hpp>
#include "engine.hpp"
<<<<<<< HEAD
#include "TextureLoaderPrototypeFactory.hpp"
#include "TestAnimatedCircle.hpp"
#include "MusicSystem.hpp"
#include "SoundSystem.hpp"
=======
#include "GUI/GUI.hpp"
>>>>>>> ff14bcc (merge)

class game : public engine::engine{
    public:
    void onStart() override
    {
        TextureLoaderPrototypeFactory::getInstance("res/textures/");
        musicSystem = MusicSystem::getInstance();
        soundSystem = SoundSystem::getInstance();
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
        GUIRenderLayer.draw(rect);
        ObjectRenderLayer.draw(testCircle->draw());
    }
    private:
<<<<<<< HEAD
    TestAnimatedCircle* testCircle;
    MusicSystem* musicSystem;
    SoundSystem* soundSystem;
=======
        sf::CircleShape* circle;

>>>>>>> ff14bcc (merge)
};

int main()
{
    game test;
    test.start();
    return 0;
}