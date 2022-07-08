#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Layers.hpp"
#include "Standard/math.hpp"

class Node : std::enable_shared_from_this<Node> {
    
    using StrongNode = std::shared_ptr<Node>;
    using WeakNode = std::weak_ptr<Node>;

    protected:
    Layers::layer_ptr render_layer = Layers::get_instance()->get_layer(1);
    private:
        std::vector<StrongNode> children;
        WeakNode parent;

        sf::Transformable local_transform;
        sf::Transformable global_transform;

        Node() = default;
        
    // UPDATE FUNCTIONS
        void draw() const;
        void update(const sf::Time& delta);
        void update_transform();

    protected:
        virtual void onDraw() const {}
        virtual void onUpdate(const sf::Time& delta) {}

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

    //MOVEMENT
        //void translate(float x, float y);
        void translate(sf::Vector2f vec);
        //void setTranslation(float x, float y);
        void setTranslation(sf::Vector2f vec);
        
        void rotate(float deegres);
        void setRotation(float deegres);
        
        //void scale(float x, float y);
        void scale(sf::Vector2f vec);
        //void setScale(float x, float y);
        void setScale(sf::Vector2f vec);

        sf::Vector2f getGlobalTranslation() {return global_transform.getPosition();}
        float getGlobalRotation() {return global_transform.getRotation();}
        sf::Vector2f getGlobalScale() {return global_transform.getScale();}
        sf::Vector2f getLocalTranslation() {return local_transform.getPosition();}
        float getLocalRotation() {return local_transform.getRotation();}
        sf::Vector2f getLocalScale() {return local_transform.getScale();}
        
};