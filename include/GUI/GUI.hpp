#pragma once
#include "Node.hpp"

class GUI : public Node
{
protected:
    Layers::layer_ptr render_layer = Layers::get_instance()->get_layer(0);

protected:
    //virtual void onCreate() {}
    virtual void onDraw() const {}
    virtual void onUpdate(const sf::Time& delta) {}
};