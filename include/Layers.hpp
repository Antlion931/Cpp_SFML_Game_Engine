#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <memory>

class Layers
{
    using layer_ptr = std::shared_ptr<sf::RenderTexture>;
public:
    static Layers *get_instance();
    void add_layer(const sf::RenderWindow &window,std::string name = "layer");
    layer_ptr get_layer(unsigned long id = 1);
    layer_ptr get_layer(std::string name);
    std::vector<layer_ptr> get_layers();

private:
    static Layers* m_instance;

    std::vector<layer_ptr> m_layers;
    std::unordered_map<std::string, layer_ptr> m_mappings;

private:
    Layers(){}
    ~Layers(){}
};