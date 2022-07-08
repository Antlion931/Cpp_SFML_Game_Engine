#pragma once 
#include "vector.hpp"

namespace engine {
    class BoundingBox {
        public:
            Vec2f top_left;
            Vec2f bottom_right;

            BoundingBox(float top_left_x, float top_left_y, float bottom_right_x, float bottom_right_y) : top_left(top_left_x, top_left_y), bottom_right(bottom_right_x, bottom_right_y) {}
            BoundingBox(Vec2f top_left, Vec2f bottom_right) : top_left(top_left), bottom_right(bottom_right) {}


            bool overlaps(const BoundingBox& other) {
                Vec2f intersect_top_left = {std::max(top_left.x, other.top_left.x), std::max(top_left.y, other.top_left.y)}; 
                Vec2f intersect_bottom_right = {std::min(bottom_right.x, other.bottom_right.x), std::min(bottom_right.y, other.bottom_right.y)};

                return intersect_top_left.x <= intersect_bottom_right.x && intersect_top_left.y <= intersect_bottom_right.y; 
            }

            bool operator&(const BoundingBox& other) {
                return overlaps(other);
            }
    };
}