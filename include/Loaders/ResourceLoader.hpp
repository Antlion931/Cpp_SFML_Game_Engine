#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class ResourceLoader
{
public:
    using font_ptr = std::shared_ptr<sf::Font>;
public:
    font_ptr get_font(unsigned int index);
    void load_font(std::string name);

    static ResourceLoader* get_instance();
private:
    std::vector<font_ptr> fonts;

    static ResourceLoader* m_instance;
};