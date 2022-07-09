#include "Track.hpp"
#include <iostream>

Track::Track(sf::Vector2f left, sf::Vector2f right) : 
    trackColor(100,100,100), barsColor(134,82,45), barsMultiplayer(1.5f), 
    left_line(sf::Vertex(left, {100,100,100}), 10), right_line(sf::Vertex(right, {100,100,100}), 10),
    bar_line(10)
{
    sf::Vertex* buffor = new sf::Vertex[2];

    buffor[0].color = trackColor;
    buffor[0].position = left;

    buffor[1].color = trackColor;
    buffor[1].position = left;

    leftTrack.push_back(buffor);
    
    buffor = new sf::Vertex[2];

    buffor[0].color = trackColor;
    buffor[0].position = right;

    buffor[1].color = trackColor;
    buffor[1].position = right;

    rightTrack.push_back(buffor);

    bars.push_back(makeBar(left, right));


}

sf::Vertex* Track::makeBar(sf::Vector2f left, sf::Vector2f right)
{
    sf::Vector2f center((left.x + right.x)/ 2.0, (left.y + right.y)/ 2.0);
    left.x = (left.x - center.x)*barsMultiplayer + center.x;
    left.y = (left.y - center.y)*barsMultiplayer + center.y;
    right.x = (right.x - center.x)*barsMultiplayer + center.x;
    right.y = (right.y - center.y)*barsMultiplayer + center.y;
    
    sf::Vertex* buffor = new sf::Vertex[2];

    buffor[0].color = barsColor;
    buffor[0].position = left;

    buffor[1].color = barsColor;
    buffor[1].position = right;

    return buffor;
}

void Track::add(sf::Vector2f left, sf::Vector2f right)
{
    sf::Vertex* buffor = new sf::Vertex[2];

    buffor[0].color = trackColor;
    buffor[0].position = leftTrack.back()[1].position;

    buffor[1].color = trackColor;
    buffor[1].position = left;

    leftTrack.push_back(buffor);
    
    buffor = new sf::Vertex[2];

    buffor[0].color = trackColor;
    buffor[0].position = rightTrack.back()[1].position;

    buffor[1].color = trackColor;
    buffor[1].position = right;

    rightTrack.push_back(buffor);

    buffor = new sf::Vertex[2];
    
    buffor = makeBar(left,right);

    bars.push_back(buffor);

    bar_line.append_segment(buffor[0], buffor[1]);

    left_line.append_vertex(sf::Vertex(left, trackColor));
    right_line.append_vertex(sf::Vertex(right, trackColor));
}

void Track::Draw(sf::RenderWindow& window)
{
    bar_line.draw(window, sf::RenderStates());
    left_line.draw(window, sf::RenderStates());
    right_line.draw(window, sf::RenderStates());
}

Track::~Track()
{
    for(auto line : bars)
    {
        delete[] line;
    }

    for(auto line : leftTrack)
    {
        delete[] line;
    }
    
    for(auto line : rightTrack)
    {
        delete[] line;
    }
}
