#pragma once
#include "Node.hpp"
#include "Hex.hpp"
#include "Standard/math.hpp"
#include "AtlasManager.hpp"
#include <vector>

class Grid : public Node{
public:
    using hex_grid = std::vector<unsigned int>;

    Hex& get(engine::Vec2i position);
    Hex& get(unsigned int x, unsigned int y);

    Grid(engine::Vec2i size) : size(size){
        hexGrid.resize(size.x * size.y);
    }
    ~Grid(){
        delete atlasManager;
    }
private:
    AtlasManager* atlasManager;
    hex_grid hexGrid;

    engine::Vec2i size;
protected:
    virtual void onDraw() const {
        sf::RenderStates state;
        state.texture = atlasManager->get_texture().get();
        state.transform = global_transfrom.getTransform();
        (*layers)[1]->draw(vertices,state);
    }
    virtual void onUpdate(const sf::Time& delta) {}
};