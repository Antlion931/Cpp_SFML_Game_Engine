#include "Nodes/Node.hpp"
#include "GUI/text.hpp"
#include "AnimationManager.hpp"

class Town : public Node
{
public:
    Town(std::string _name, bool isItBig, sf::Vector2f position);
    void onReady();
    void Repair();
    void onUpdate(const sf::Time& delta);
    void onDraw() const;
private:
    std::string name;
    AnimationManager animationManager;
    sf::RectangleShape body;
    std::shared_ptr<engine::Text> text;
};
