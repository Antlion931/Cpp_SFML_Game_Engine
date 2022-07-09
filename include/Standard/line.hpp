#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "math.hpp"

namespace engine {
    class PolyLine : public sf::Drawable{
        sf::VertexArray triangled_vertices = sf::VertexArray(sf::TriangleStrip);
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

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                target.draw(triangled_vertices, states);
            }

            PolyLine(sf::Vertex start_point, float thickness) {
                //triangled_vertices.resize(1000);
                last_vertex = start_point;
                this->thickness = thickness;
            }

            void append_vertex(sf::Vertex vertex) {
                std::vector<sf::Vertex> result = triangulate_line(last_vertex, vertex);
                for(auto res : result) {
                    triangled_vertices.append(res);
                }
                last_vertex = vertex;
            }
    };

    class DisconnectedLine : public sf::Drawable {
        sf::VertexArray triangled_vertices = sf::VertexArray(sf::Quads);
        float thickness;

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

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
                target.draw(triangled_vertices, states);
            }

            DisconnectedLine(float thickness) {
                this->thickness = thickness;
            }

            void append_segment(sf::Vertex start, sf::Vertex end) {
                std::vector<sf::Vertex> result = triangulate_line(start, end);
                for(auto res : result) {
                    triangled_vertices.append(res);
                }
            }
    };
}