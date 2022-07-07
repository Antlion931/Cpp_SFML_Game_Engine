#include <memory>
#include <vector>

class Node : std::enable_shared_from_this<Node> {
    
    using StrongNode = std::shared_ptr<Node>;
    using WeakNode = std::weak_ptr<Node>;

    private:
        std::vector<StrongNode> children;
        WeakNode parent;

        Node() = default;

    public:

        void change_parent(StrongNode new_parent) {
            if(auto locked_parent = parent.lock()){
                locked_parent->remove_child(shared_from_this());
            }
            new_parent->children.push_back(shared_from_this());
            parent = new_parent;
        }

        void remove_child(StrongNode child) {
            children.erase(std::find(children.begin(),children.end(),child));
        }

        static StrongNode create(StrongNode parent) {
            StrongNode new_node = std::shared_ptr<Node>(new Node());
            
            parent->children.push_back(new_node);
            new_node->parent = parent;

            return new_node;
        }

        static StrongNode create() {
            StrongNode new_node = std::shared_ptr<Node>(new Node());

            return  new_node;
        }

};