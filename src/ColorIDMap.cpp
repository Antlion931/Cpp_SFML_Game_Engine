#include "Nodes/Node.hpp"
#include "ColorIDMap.hpp"

ColorIDMap* ColorIDMap::m_instance = nullptr;
sf::Shader* ColorIDMap::color_id_shader = nullptr;

ColorIDMap* ColorIDMap::get_instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ColorIDMap();
        color_id_shader = new sf::Shader();
        if(!color_id_shader->loadFromFile("res/shaders/color_id_shader.vert","res/shaders/color_id_shader.frag"))
            std::cout << "Failed to load shaders!\n";
        color_id_shader->setUniform("texture", sf::Shader::CurrentTexture);
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

    curr_node_id+=9777;

    return color;
}

ColorIDMap::layer_ptr ColorIDMap::get_color_layer()
{
    return m_color_layer;
}

std::optional<sf::Color> ColorIDMap::get_color_at(engine::Vec2i at) {
    sf::Vector2i position = at;
    auto image = m_color_layer->getTexture().copyToImage();
    if(!((position.x < 0 || position.x >= image.getSize().x) || (position.y < 0 || position.y >= image.getSize().y)) )
    {
        auto color = image.getPixel(position.x,position.y);
        if(color.r != 0 || color.g != 0 || color.b != 0 || color.a != 0) {
            return std::optional<sf::Color>(color);
        }
    }
    return {};
}

std::optional<sf::Color> ColorIDMap::get_color_at_world(engine::Vec2f at) {
    return get_color_at(m_color_layer->mapCoordsToPixel(at));
}

void ColorIDMap::set_window(sf::RenderWindow* _window)
{
    window = _window;
}