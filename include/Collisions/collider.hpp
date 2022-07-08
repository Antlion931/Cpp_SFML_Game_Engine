#include "Standard/math.hpp"
#include <vector>

namespace engine {
    class CollisionShape {
        public :
            virtual Vec2f support(const Vec2f& direction) const = 0;  
    }; 

    class CollisionCircle : public CollisionShape {
        float radius;
        public :
            virtual Vec2f support(const Vec2f& direction) const override {
                return direction / direction.length() * radius;
            }

            CollisionCircle(float radius) : radius(radius) {}
    };

    
    class CollisionPolygon : public CollisionShape {
        
        std::vector<Vec2f> vertices;
        public :
            virtual Vec2f support(const Vec2f& direction) const override {
                Vec2f max_point = vertices[0];
                float max_dot = vertices[0].dot(direction);
                
                for(auto vertex : vertices) {
                    float temp_dot = vertex.dot(direction);
                    if(temp_dot > max_dot) {
                        max_dot = temp_dot;
                        max_point = vertex;
                    }
                }

                return max_point;
            }

            CollisionPolygon(std::vector<Vec2f> vertices) : vertices(vertices) {}
    };

    class CollisionRectangle : public CollisionPolygon {
        public:
            CollisionRectangle(Vec2f top_left, Vec2f bottom_right) : CollisionPolygon({top_left, {top_left.x, bottom_right.y}, bottom_right, {bottom_right.x, top_left.y}}) {}
    };
}