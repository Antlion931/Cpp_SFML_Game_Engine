#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class Node : std::enable_shared_from_this<Node>, sf::Drawable {
    
    using StrongNode = std::shared_ptr<Node>;
    using WeakNode = std::weak_ptr<Node>;

    private:
        std::vector<StrongNode> children;
        WeakNode parent;

        sf::RenderTexture& render_layer;

        Node() = default;

    public:
    // MANAGING CHILDREN / PARENTS
        void change_parent(StrongNode new_parent);
        void remove_child(StrongNode child);

    // FACTORY PATTERN
        static StrongNode create(StrongNode parent);
        static StrongNode create();

    // GETTERS AND SETTERS
        void setActive(bool _active);
        bool isActive();

        void setVisible(bool _visible);
        bool isVisible();

    // UPDATE FUNCTIONS
};