#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cctype>

class Layers
{
public:
    static Layers *get_instance()
    {
        if(m_instance == nullptr)
            m_instance = new Layers();
        return m_instance;
    }

    void add_layer(const sf::RenderWindow &window,std::string name = "layer")
    {
        std::transform(name.begin(), name.end(), name.begin(),
            [](unsigned char c){ return std::tolower(c); });

        sf::RenderTexture layer;

        layer.create(window.getSize().x,window.getSize().y);

        if(m_mappings.count(name) > 0)
        {
            name = name + std::to_string(m_mappings.count(name) + 1);
        }

        m_mappings[name] = &layer;
        m_layers.push_back(&layer);
    }
    sf::RenderTexture* get_layer(unsigned long id = 1)
    {
        // we return the furthest layer
        id = std::min(m_layers.size() - 1, id);
        return m_layers[id];
    }
    sf::RenderTexture* get_layer(std::string name)
    {
        std::transform(name.begin(), name.end(), name.begin(),
            [](unsigned char c){ return std::tolower(c); });
            // POTENTIALLY DANGEROUS!
            // MOZLIWE ZE NIE ISTNIEJE WARSTWA O TAKIEJ NAZWIE
            // TRZEBA JAKOS TMEU ZAPOBIEC
        return m_mappings[name];
    }
    std::vector<sf::RenderTexture*> get_layers() { return m_layers; }

private:
    static Layers* m_instance;

    std::vector<sf::RenderTexture*> m_layers;
    std::unordered_map<std::string, sf::RenderTexture*> m_mappings;
public:
    Layers(Layers &other) = delete;
    void operator=(const Layers &) = delete;
private:
    Layers(){}
    ~Layers(){}
};