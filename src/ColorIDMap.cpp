#include "Nodes/Node.hpp"
#include "ColorIDMap.hpp"

ColorIDMap* ColorIDMap::m_instance = nullptr;

ColorIDMap* ColorIDMap::get_instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ColorIDMap();
    }
    return m_instance;
}


sf::Color ColorIDMap::generate_unique_color_id(std::weak_ptr<Node> node)
{
    int blue  = 0;
    int green = 0;
    int red   = 0;
    unsigned int id = curr_node_id;

    blue =  id % 256;
    id /= 256;
    green = id % 256;
    id /= 256;
    red =   id % 256;
    
    auto color = sf::Color(red,green,blue,255);
    m_color_map[color] = node;

    curr_node_id++;

    return color;
}

ColorIDMap::layer_ptr ColorIDMap::get_color_layer()
{
    return m_color_layer;
}

std::optional<std::weak_ptr<Node>> ColorIDMap::get_hovered_object()
{
    sf::Vector2i position = sf::Mouse::getPosition(*window);
    auto image = m_color_layer->getTexture().copyToImage();
    if(!((position.x < 0 || position.x > image.getSize().x) || (position.y < 0 || position.y > image.getSize().y)) )
    {
        auto color = image.getPixel(position.x,position.y);
        if(m_color_map.count(color) > 0)
        {
            return std::optional<std::weak_ptr<Node>>(m_color_map[color]);
        }
    }
    return {};
}

void ColorIDMap::set_window(sf::RenderWindow* _window)
{
    window = _window;
}