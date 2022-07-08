#include "ColorIDMap.hpp"
#include <memory>
#include <vector>
#include <algorithm>
#include "Node.hpp" 

using StrongNode = std::shared_ptr<Node>;
using WeakNode = std::weak_ptr<Node>;

Node::Node()
{
    color_id = ColorIDMap::get_instance()->generate_unique_color_id(weak_from_this());
}

void Node::change_parent(StrongNode new_parent) {
    if(auto locked_parent = parent.lock()){
        locked_parent->remove_child(shared_from_this());
    }
    new_parent->children.push_back(shared_from_this());
    parent = new_parent;
}

void Node::remove_child(StrongNode child) {
    children.erase(std::find(children.begin(),children.end(),child));
}

StrongNode Node::create(StrongNode parent) {
    StrongNode new_node = std::shared_ptr<Node>(new Node());
    
    parent->children.push_back(new_node);
    new_node->parent = parent;

    return new_node;
}

StrongNode Node::create() {
    StrongNode new_node = std::shared_ptr<Node>(new Node());

    return  new_node;
}

void Node::draw() const {
    onDraw();

    for(auto child : children) {
        child->draw();
    }
}

void Node::update(const sf::Time& delta) {
    onUpdate(delta);

    for(auto child : children) {
        child->update(delta);
    }
}

void Node::update_transform() {
    if(auto locked_parent = parent.lock()) {
        global_transform = combineTransforms(locked_parent->global_transform, local_transform);
    }
    else {
        global_transform = local_transform;
    }

    for(auto child : children) {
        child->update_transform();
    }
}

void Node::translate(sf::Vector2f vec) {
    local_transform.move(vec);
    update_transform();
}
void Node::setTranslation(sf::Vector2f vec) {
    local_transform.setPosition(vec);
    update_transform();
}

void Node::rotate(float deegres) {
    local_transform.rotate(deegres);
    update_transform();
}
void Node::setRotation(float deegres) {
    local_transform.setRotation(deegres);
    update_transform();
}

void Node::scale(sf::Vector2f vec) {
    local_transform.scale(vec);
    update_transform();
}
void Node::setScale(sf::Vector2f vec) {
    local_transform.setScale(vec);
    update_transform();
}
