/*#include <memory>
#include <vector>
#include <algorithm>
#include "Node.hpp" 

using StrongNode = std::shared_ptr<Node>;
using WeakNode = std::weak_ptr<Node>;

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
}*/