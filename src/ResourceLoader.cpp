#include "Loaders/ResourceLoader.hpp"
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>

using font_ptr = std::shared_ptr<sf::Font>;

ResourceLoader* ResourceLoader::m_instance = nullptr;

font_ptr ResourceLoader::get_font(unsigned int index)
{
    return fonts.at(index);
}
void ResourceLoader::load_font(std::string name)
{
    sf::Font font;
    font.loadFromFile("res/fonts/" + name);
    fonts.push_back(std::make_shared<sf::Font>(font));
}

ResourceLoader* ResourceLoader::get_instance()
{
    if(m_instance == nullptr)
        m_instance = new ResourceLoader();
    return m_instance;
}

using texture_ptr = std::shared_ptr<sf::Texture>;
texture_ptr ResourceLoader::get_texture(std::string name)
{
    return textures.at(name);
}
void ResourceLoader::load_texture(std::string path)
{
    texture_ptr texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(path))
        std::cout << "Failed to load texture from: " << path << std::endl;
    auto pos = path.find_last_of('/');
    textures[path.substr(pos + 1, path.length())] = texture;
}