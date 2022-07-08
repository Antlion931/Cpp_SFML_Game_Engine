#pragma once
#include <memory>
#include "Node.hpp"
#include <unordered_map>
#include "Standard/Hashers.hpp"
#include <SFML/Graphics.hpp>

class Node;

class ColorIDMap
{
public:
    using layer_ptr = std::shared_ptr<sf::RenderTexture>;

    static ColorIDMap* get_instance();
    sf::Color generate_unique_color_id(std::weak_ptr<Node> node);

    layer_ptr get_color_layer();
    
private:
    static ColorIDMap* m_instance;

    unsigned long long curr_node_id = 0;
    std::unordered_map<sf::Color, std::weak_ptr<Node>> m_color_map;

    layer_ptr m_color_layer = std::make_shared<sf::RenderTexture>();

    ColorIDMap() = default;
};