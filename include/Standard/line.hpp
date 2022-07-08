#include "SFML/Graphics.hpp"
#include <vector>
#include "math.hpp"

namespace engine {
    class PolyLine{
        sf::VertexBuffer triangled_vertices = sf::VertexBuffer(sf::TriangleStrip, sf::VertexBuffer::Usage::Stream);
        int vertices_in_buffer = 0;
        float thickness;
        sf::Vertex last_vertex;

        private:
            std::vector<sf::Vertex> triangulate_line(sf::Vertex start, sf::Vertex end) {
                Vec2f start_vec = Vec2f(start.position);
                Vec2f end_vec = Vec2f(end.position);

                Vec2f line_dir = (end_vec - start_vec).norm();

                Vec2f perp_dir = line_dir.perpendicular() * thickness;

                std::vector<sf::Vertex> triangulated_vertices = {sf::Vertex(start_vec + perp_dir, start.color, start.texCoords), 
                                                                sf::Vertex(start_vec - perp_dir, start.color, start.texCoords),
                                                                sf::Vertex(end_vec + perp_dir, end.color, end.texCoords),
                                                                sf::Vertex(end_vec - perp_dir, end.color, end.texCoords)};
                
                return triangulated_vertices;
            }

        public:

            PolyLine(sf::Vertex start_point, float thickness) {
                triangled_vertices.create(1000);
                
                last_vertex = start_point;
                this->thickness = thickness;
            }

            void append_vertex(sf::Vertex vertex) {
                sf::Vertex* points = &triangulate_line(last_vertex, vertex)[0];
                triangled_vertices.update(points, 4, vertices_in_buffer);
                vertices_in_buffer += 4;
                last_vertex = vertex;
            }
    };
}