#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Standard/math.hpp"
#include "Loaders/ResourceLoader.hpp"
#include "AtlasManager.hpp"

class AtlasManager
{
public:
    struct animation{
        float frame_duration;
        engine::Vec2i begin_frame;
        unsigned int frame_count;
    };
public:
    using animation_map = std::unordered_map<std::string,animation>;

    AtlasManager(const std::string& tileSetName, engine::Vec2i tileSize,
    animation_map animation) : tileSize(tileSize), animationMap(animation)
    {
        std::cout << "res/textures/tilesets/"+tileSetName << std::endl;
        ResourceLoader* resourceLoader = ResourceLoader::get_instance();
        resourceLoader->load_texture("res/textures/tilesets/"+tileSetName);
        tileSet = resourceLoader->get_texture(tileSetName);
    }

    std::tuple<sf::Vector2f,sf::Vector2f,sf::Vector2f,sf::Vector2f> get_texture_coords_at(unsigned int i, unsigned int j)
    {
        return {sf::Vector2f(i * tileSize.x, j * tileSize.y),
                sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y),
                sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y),
                sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y)};
    }
    std::tuple<sf::Vector2f,sf::Vector2f,sf::Vector2f,sf::Vector2f> get_texture_coords_at(engine::Vec2i c)
    {
        return {sf::Vector2f(c.x * tileSize.x, c.y * tileSize.y),
                sf::Vector2f((c.x + 1) * tileSize.x, c.y * tileSize.y),
                sf::Vector2f((c.x + 1) * tileSize.x, (c.y + 1) * tileSize.y),
                sf::Vector2f(c.x * tileSize.x, (c.y + 1) * tileSize.y)};
    }

    void update(const sf::Time& delta)
    {
        current_time += delta;
    }

    engine::Vec2i get_frame(const std::string& name)
    {
        auto animation = animationMap[name];
        int frame = current_time.asSeconds() / animation.frame_duration;
        frame %= animation.frame_count;

        return engine::Vec2i(animation.begin_frame.x + frame, animation.begin_frame.y);
    }

    std::shared_ptr<sf::Texture> get_texture()
    {
        return tileSet;
    }

private:
    std::shared_ptr<sf::Texture> tileSet;
    engine::Vec2i tileSize;

    animation_map animationMap;
    sf::Time current_time;
};