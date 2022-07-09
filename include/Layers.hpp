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
public:
    using layer_ptr = std::shared_ptr<sf::RenderTexture>;
    static Layers *get_instance();
    void add_layer(const sf::RenderWindow &window,std::string name = "layer");
    layer_ptr get_layer(unsigned long id = 1);
    layer_ptr get_layer(std::string name);
    std::vector<layer_ptr>& get_layers();

    layer_ptr get_color_layer();

    layer_ptr operator[](unsigned long id);
    layer_ptr operator[](std::string name);

private:
    static Layers* m_instance;

    std::vector<layer_ptr> m_layers;
    std::unordered_map<std::string, layer_ptr> m_mappings;

private:
    Layers(){}
    ~Layers(){}
};