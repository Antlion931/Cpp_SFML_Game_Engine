#include "Node.hpp"
#include "Track.hpp"
#include "AnimationManager.hpp"

class Train : public Node
{
public:
    Train();
    void onUpdate(const sf::Time& delta);
    void onDraw() const;

private:
    float speed = -100.0f;
    float angle = 0.0f;
    //Track track;
    AnimationManager animationManager;
    sf::RectangleShape body;
};
