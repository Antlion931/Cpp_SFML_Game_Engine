#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <memory>
#include "Layers.hpp"

Layers* Layers::m_instance = nullptr;

using layer_ptr = std::shared_ptr<sf::RenderTexture>;

Layers* Layers::get_instance()
{
    if(m_instance == nullptr)
        m_instance = new Layers();
    return m_instance;
}

void Layers::add_layer(const sf::RenderWindow &window,std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });

    layer_ptr layer = std::make_shared<sf::RenderTexture>();

    layer->create(window.getSize().x,window.getSize().y);

    if(m_mappings.count(name) > 0)
    {
        name = name + std::to_string(m_mappings.count(name) + 1);
    }

    m_mappings[name] = layer;
    m_layers.push_back(layer);
}
layer_ptr Layers::get_layer(unsigned long id)
{
    // we return the furthest layer
    id = std::min(m_layers.size() - 1, id);
    return m_layers[id];
}
layer_ptr Layers::get_layer(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });
        // POTENTIALLY DANGEROUS!
        // MOZLIWE ZE NIE ISTNIEJE WARSTWA O TAKIEJ NAZWIE
        // TRZEBA JAKOS TMEU ZAPOBIEC
    return m_mappings[name];
}
std::vector<layer_ptr> Layers::get_layers() { return m_layers; }