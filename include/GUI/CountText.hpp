#include "GUI/text.hpp"
#include <cmath>

class CountText : public engine::Text
{
public:
    CountText(std::string _text) : engine::Text(_text) 
    {};
    virtual void onUpdate(const sf::Time& delta)
    {
        currentTime += delta.asSeconds();
        text.setColor(sf::Color(255, 255, 255, 255 * std::max(1 - currentTime, 0.f)));
        text.setOutlineColor(sf::Color(0, 0, 0, 255 * std::max(1 - currentTime, 0.f)));
        text.setCharacterSize(100.0f * std::max(1 - currentTime, 0.f));
    }
private:
    float currentTime = 0.0f;
};
