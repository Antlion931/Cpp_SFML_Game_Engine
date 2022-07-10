#include "ColorLookup.hpp"
#include "Track.hpp"
#include "ColorLookup.hpp"
#include <iostream>

Track::Track(sf::Vector2f left, sf::Vector2f right) : 
    trackColor(100,100,100), barsColor(134,82,45), barsMultiplayer(1.7f), 
    left_line(sf::Vertex(left, {100,100,100}), 1), right_line(sf::Vertex(right, {100,100,100}), 1),
    bar_line(4), el_train([this](std::shared_ptr<Node> train) {
        std::dynamic_pointer_cast<Train>(train)->die();
    })
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

void Track::onDraw() const
{
    bar_line.draw(*render_layer, global_transform.getTransform());
    left_line.draw(*render_layer, global_transform.getTransform());
    right_line.draw(*render_layer, global_transform.getTransform());
    auto shader = ColorIDMap::color_id_shader;
    shader->setUniform("color_id", sf::Glsl::Vec4(color_id));
    ColorIDMap::get_instance()->get_color_layer()->draw(bar_line, shader);
    ColorIDMap::get_instance()->get_color_layer()->draw(left_line, shader);
    ColorIDMap::get_instance()->get_color_layer()->draw(right_line, shader);
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

void Track::onReady() {
    ColorLookup::get_instance()->register_train_hit(color_id,el_train);

}
