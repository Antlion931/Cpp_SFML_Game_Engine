#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Standard/math.hpp"
#include "Layers.hpp"
#include <optional>
#include <unordered_map>
#include "Standard/Hashers.hpp"

class Node;
class SpriteNode;

class ColorIDMap
{
public:
    using layer_ptr = std::shared_ptr<sf::RenderTexture>;

    static ColorIDMap* get_instance();
    sf::Color generate_unique_color_id(std::weak_ptr<Node> node);

    layer_ptr get_color_layer();

    std::optional<std::weak_ptr<Node>> get_hovered_object();

    void set_window(sf::RenderWindow* _window);
    
private:
    static ColorIDMap* m_instance;

    unsigned long long curr_node_id = 255;
    std::unordered_map<sf::Color, std::weak_ptr<Node>> m_color_map;

    layer_ptr m_color_layer;

    const sf::RenderWindow* window;

    ColorIDMap()
    {
        m_color_layer = std::make_shared<sf::RenderTexture>();
        m_color_layer->create(800,800);
    }
};


template<class T>
concept DerivedFromNode = std::is_base_of<Node, T>::value;


class Node : std::enable_shared_from_this<Node> {
public:
    using StrongNode = std::shared_ptr<Node>;
    using WeakNode = std::weak_ptr<Node>;

    protected:
        Layers::layer_ptr render_layer = Layers::get_instance()->get_layer(1);
        Node() = default;
    private:
        std::vector<StrongNode> children;
        WeakNode parent;

        sf::Transformable local_transform;
        sf::Transformable global_transform;


    protected:
        sf::Color color_id;
        
        virtual void onDraw() const {}
        virtual void onUpdate(const sf::Time& delta) {}
        virtual void onCreate() {};

    public:
    // UPDATE FUNCTIONS
        void draw() const;
        void update(const sf::Time& delta);
        void update_transform();
    // MANAGING CHILDREN / PARENTS
        void change_parent(StrongNode new_parent);
        void remove_child(StrongNode child);

    // FACTORY PATTERN
        template<DerivedFromNode T>
        static std::shared_ptr<T> create(StrongNode parent);
        template<DerivedFromNode T>
        static std::shared_ptr<T> create();

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

template<DerivedFromNode T>
std::shared_ptr<T> Node::create() {
    std::shared_ptr<T> new_node = std::shared_ptr<T>(new T());
    
    new_node->color_id = ColorIDMap::get_instance()->generate_unique_color_id(new_node);

    new_node->onCreate();

    return new_node;
}

template<DerivedFromNode T>
std::shared_ptr<T> Node::create(StrongNode parent) {
    std::shared_ptr<T> new_node = create<T>();
    
    parent->children.push_back(new_node);
    new_node->parent = parent;

    return new_node;
}