#pragma once
#include "Node.hpp"
#include "Hex.hpp"
#include "Standard/math.hpp"
#include "AtlasManager.hpp"
#include <vector>
#include "Layers.hpp"

class Grid : public Node{
public:
    using hex_grid = std::vector<unsigned int>;

    unsigned int get(engine::Vec2i position) { return hexGrid[position.x % size.x + position.y % size.x];}
    unsigned int get(unsigned int x, unsigned int y) { return hexGrid[x % size.x + y % size.x];}

    Grid(engine::Vec2i size, std::string tilesetName, engine::Vec2i tileSize) : size(size), tileSize(tileSize){
        atlasManager = new AtlasManager(tilesetName,tileSize,{});

        // LOAD VERTICES
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(size.x * size.y * 4);
        for (unsigned int i = 0; i < size.x; ++i)
        for (unsigned int j = 0; j < size.y; ++j)
        {
            sf::Vertex *quad = &vertices[(i + j * size.x) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // ustaw puste tekstury
            quad[0].texCoords = sf::Vector2f(); // left top
            quad[1].texCoords = sf::Vector2f(); // right top
            quad[2].texCoords = sf::Vector2f(); // right bottom
            quad[3].texCoords = sf::Vector2f(); // left bottom
        }

        hexGrid.resize(size.x * size.y);
    }
    void setTile(engine::Vec2i position, unsigned int tileID)
    {
        if(tileID == -1)
            return;

        std::cout << size.x << ", " << tileSize.x << std::endl;
        int tu = tileID % (atlasManager->get_texture()->getSize().x / tileSize.x);
        int tv = tileID / (atlasManager->get_texture()->getSize().x / tileSize.x);


        sf::Vertex *quad = &vertices[(position.x + position.y * size.x) * 4];

        quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y); // left top
        quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y); // right top
        quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y); // right bottom
        quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y); // left bottom
    }
    ~Grid(){
        delete atlasManager;
    }
    void loadTileDataFromFile(std::string filePath)
    {
        for(int i = 0; i < size.x; i++)
        {
            for(int j = 0; j < size.y; j++)
            {
                setTile({i,j},0);
            }
        }
    }
private:
    AtlasManager* atlasManager;
    hex_grid hexGrid;

    engine::Vec2i size;
    engine::Vec2i tileSize;

    Layers* layers = Layers::get_instance();

    sf::VertexArray vertices;
protected:
    virtual void onDraw() const {
        sf::RenderStates state;
        state.texture = atlasManager->get_texture().get();
        state.transform = global_transform.getTransform();
    (*layers)[3]->draw(vertices,state);
    }
    virtual void onUpdate(const sf::Time& delta) {}
};