#pragma once
#include "Node.hpp"
#include "Standard/math.hpp"
#include "AtlasManager.hpp"
#include <vector>
#include "Layers.hpp"
#include <fstream>

class Grid : public Node{
public:
    struct hex {
        int current_tile;
        int basic_tile;
        int original_tile;
        int phase;
        engine::Vec2f pos;
    };
    using hex_grid = std::vector<hex>;

    //unsigned int get(engine::Vec2i position) { return hexGrid[position.x % size.x + position.y % size.x];}
    //unsigned int get(unsigned int x, unsigned int y) { return hexGrid[x % size.x + y % size.x];}

    Grid(engine::Vec2i size, std::string tilesetName, engine::Vec2i tileSize) : size(size), tileSize(tileSize){
        atlasManager = new AtlasManager(tilesetName,tileSize,{});

        // LOAD VERTICES
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(size.x * size.y * 4);
        hexGrid.resize(size.x * size.y);
        loadTileDataFromFile("res/mapa.csv");

        for (int i = 0; i < size.x; ++i)
        for ( int j = 0; j < size.y; ++j)
        {
            float offsetx = (j % 2 == 1) * 16;
            float offsety = j * 10;
            //float offsetx0p = (j % 2 == 1) * 15 - 2 * i;
            //float offsety0p = j * 12;

            sf::Vertex *quad = &vertices[(i + j * size.x) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x + offsetx, j * tileSize.y - offsety);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x + offsetx, j * tileSize.y - offsety);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x + offsetx, (j + 1) * tileSize.y - offsety);
            quad[3].position = sf::Vector2f(i * tileSize.x + offsetx, (j + 1) * tileSize.y - offsety);
            hexGrid[(i + j * size.x)].pos = {i * tileSize.x + offsetx + 0.5f * tileSize.x, j * tileSize.y - offsety + 0.5f * tileSize.y};
        }

    }
    void setTile(engine::Vec2i position, unsigned int tileID)
    {
        if(tileID == -1)
            return;

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

    void change_nearby_points(engine::Vec2f pos ,float radius) {
        for(auto &point : hexGrid) {
            if((pos - engine::Vec2f(global_transform.getTransform() * point.pos)).length_sq() < radius*radius) {
                point.basic_tile = point.original_tile;
            }
        }
    }

    engine::Vec2f to_world_from_tile(engine::Vec2i tile_pos) {
        float offsetx = (tile_pos.y % 2 == 1) * 16;
        float offsety = tile_pos.y * 10;
        return engine::Vec2f(global_transform.getTransform() * engine::Vec2f{tile_pos.x * tileSize.x + offsetx + 0.5f * tileSize.x, tile_pos.y * tileSize.y - offsety + 0.5f * tileSize.y});
    }

    void loadTileDataFromFile(std::string filePath)
    {
        std::ifstream in(filePath);
        for(int j = 0; j < size.y; j++)
        {
            for(int i = 0; i < size.x; i++)
            {
                int id;
                in >> id;
                hexGrid[i + j * size.x].original_tile = id; 
                if(id == 4 || id == 8)
                    id = 0;
                if(id == 16) 
                    id = 20;
                setTile({i,j},id);
                hexGrid[i + j * size.x].basic_tile = id; 
                hexGrid[i + j * size.x].phase = std::rand()%frame_count; 
            }
        }
        in.close();
    }

    virtual void onUpdate(const sf::Time& delta) override {
        elapsed_time += delta;
        if(elapsed_time > time_between_frames) {
            elapsed_time = sf::Time::Zero;
            for (int i = 0; i < size.x; ++i)
            for ( int j = 0; j < size.y; ++j)
            {
                hexGrid[i + j * size.x].current_tile = (hexGrid[i + j * size.x].current_tile + 1) % frame_count + hexGrid[i + j * size.x].basic_tile;
                setTile({i,j}, (hexGrid[i + j * size.x].current_tile + hexGrid[i + j * size.x].phase)%4 + hexGrid[i + j * size.x].basic_tile);
            }
        }
    }
private:
    AtlasManager* atlasManager;
    hex_grid hexGrid;

    engine::Vec2i size;
    engine::Vec2i tileSize;
    
    int frame_count = 4;
    sf::Time elapsed_time = sf::Time::Zero;
    sf::Time time_between_frames = sf::seconds(0.5f);

    Layers* layers = Layers::get_instance();

    sf::VertexArray vertices;
protected:
    virtual void onDraw() const {
        sf::RenderStates state;
        state.texture = atlasManager->get_texture().get();
        state.transform = global_transform.getTransform();
    (*layers)[3]->draw(vertices,state);
    }
};