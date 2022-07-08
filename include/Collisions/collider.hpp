#include "Standard/math.hpp"

namespace engine {
    class CollisionShape {
        virtual Vec2f support(Vec2f direction) = 0;  
        
    }; 
}