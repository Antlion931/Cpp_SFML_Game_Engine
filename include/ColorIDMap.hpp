#pragma once
#include <memory>
#include "Node.hpp"
#include <unordered_map>
#include "Standard/Hashers.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

class Node;

class ColorIDMap
{
public:
    using layer_ptr = std::shared_ptr<sf::RenderTexture>;

    static ColorIDMap* get_instance();
    sf::Color generate_unique_color_id(std::weak_ptr<Node> node);

    layer_ptr get_color_layer();

    std::optional<std::weak_ptr<Node>> get_hovered_object();
    
private:
    static ColorIDMap* m_instance;

    unsigned long long curr_node_id = 255;
    std::unordered_map<sf::Color, std::weak_ptr<Node>> m_color_map;

    layer_ptr m_color_layer;

    ColorIDMap()
    {
        m_color_layer = std::make_shared<sf::RenderTexture>();
        m_color_layer->create(800,800);
    }
};