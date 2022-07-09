#include <SFML/Graphics.hpp>
#include "Layers.hpp"

class Track
{
public:
    Track(sf::Vector2f left, sf::Vector2f right);
    ~Track();
    void add(sf::Vector2f left, sf::Vector2f right);
    void Draw(sf::RenderWindow& window);

private:
    std::vector<sf::Vertex*> bars;
    std::vector<sf::Vertex*> leftTrack;
    std::vector<sf::Vertex*> rightTrack;
    sf::Color trackColor;
    sf::Color barsColor;
    float barsMultiplayer;

    sf::Vertex* makeBar(sf::Vector2f left, sf::Vector2f right);
};
