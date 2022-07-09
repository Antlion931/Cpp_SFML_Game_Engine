#include "Loaders/ResourceLoader.hpp"

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

