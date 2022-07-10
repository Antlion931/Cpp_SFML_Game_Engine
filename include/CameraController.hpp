#pragma once
#include "Nodes/Node.hpp"

class CameraController : public Node
{
private:
    sf::Vector2f required_translation = {0, 0};

public:
    CameraController()
    {

    }

    sf::Vector2f getRequiredTranslation()
    {

    }

protected:
    void onUpdate(const sf::Time& delta) override
    {
        
    }
};