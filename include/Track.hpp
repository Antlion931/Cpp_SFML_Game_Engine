#pragma once
#include <SFML/Graphics.hpp>
#include "Layers.hpp"
#include "Standard/line.hpp"
#include "Nodes/Node.hpp"

class Track : public Node
{
public:
    Track(sf::Vector2f left, sf::Vector2f right);
    ~Track();
    void add(sf::Vector2f left, sf::Vector2f right);
    void onDraw() const;
    void onReady() override;

private:
    std::vector<sf::Vertex*> bars;
    std::vector<sf::Vertex*> leftTrack;
    std::vector<sf::Vertex*> rightTrack;
    engine::PolyLine left_line;
    engine::PolyLine right_line;
    engine::DisconnectedLine bar_line;
    sf::Color trackColor;
    sf::Color barsColor;
    float barsMultiplayer;
    EventListener<std::shared_ptr<Node>> el_train;

    sf::Vertex* makeBar(sf::Vector2f left, sf::Vector2f right);
};
