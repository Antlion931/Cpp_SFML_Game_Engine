#pragma once
#include "Nodes/Node.hpp"

class Grid : public Node{
public:
    virtual void onCreate() override {}
protected:
    virtual void onDraw() const {}
    virtual void onUpdate(const sf::Time& delta) {}
};