#pragma once
#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <cmath>
#include "Loaders/ResourceLoader.hpp"

class SmokeParticles : public Node {
    struct particle {
        engine::Vec2f pos;
        engine::Vec2f vel;
        sf::Time life = sf::Time::Zero;
    };

    int number_of_particles = 300;
    sf::Time lifetime_limit = sf::seconds(3.f);
    sf::VertexArray quadrupled_particles = sf::VertexArray(sf::Quads, number_of_particles * 4);
    std::vector<particle> particles = std::vector<particle>(number_of_particles);
    engine::Vec2f dir = {0,-1};
    engine::Vec2f origin = {0,0};
    int variation = 90;
    float particle_size = 5;
    std::shared_ptr<sf::Texture> smoke_ptr;
    
    public:
    SmokeParticles() {
        ResourceLoader::get_instance()->load_texture("res/textures/smoke/smoke_particle.png");
        smoke_ptr = ResourceLoader::get_instance()->get_texture("smoke_particle.png");

        for(int i = 0; i < number_of_particles; i++) {
            resetParticle(i);
            quadrupled_particles[4*i].texCoords = sf::Vector2f{0,0};
            quadrupled_particles[4*i+1].texCoords = sf::Vector2f{(float)(smoke_ptr->getSize().x), 0};
            quadrupled_particles[4*i+2].texCoords = sf::Vector2f{(float)(smoke_ptr->getSize().x), (float)(smoke_ptr->getSize().y)};
            quadrupled_particles[4*i+3].texCoords = sf::Vector2f{0, (float)(smoke_ptr->getSize().y)};
        }
    }

    void resetParticle(int id) {
        particles[id].life = sf::Time::Zero;
        float rand_angle = (std::rand() % variation) - float(variation/2);
        float rand_rad = rand_angle * 3.14f / 180.f;

        float emitting_angle = atan2f(dir.y, dir.x);

        float sum_angle = rand_rad + emitting_angle;

        engine::Vec2f final_dir = {std::cos(sum_angle), std::sin(sum_angle)}; 

        float speed = (std::rand() % 20) + 100.f;

        particles[id].pos = origin;
        particles[id].vel = final_dir * speed;
        particles[id].life = sf::milliseconds((std::rand() % (lifetime_limit.asMilliseconds())));
    }

    void changeOrigin(engine::Vec2f new_origin) {
        origin = new_origin;
    }

    void onUpdate(const sf::Time& delta) override {
        for(int i = 0; i < number_of_particles; i++) {
            particles[i].life += delta;

            if(particles[i].life > lifetime_limit) {
                resetParticle(i);
            }

            particles[i].pos += particles[i].vel * delta.asSeconds();

            quadrupled_particles[4*i].position = particles[i].pos + engine::Vec2f{-particle_size, -particle_size};
            quadrupled_particles[4*i+1].position = particles[i].pos + engine::Vec2f{particle_size, -particle_size};
            quadrupled_particles[4*i+2].position = particles[i].pos + engine::Vec2f{particle_size, particle_size};
            quadrupled_particles[4*i+3].position = particles[i].pos + engine::Vec2f{-particle_size, particle_size};
            quadrupled_particles[4*i].color.a = (int)((1 - particles[i].life / lifetime_limit) * 120 + 135);
            quadrupled_particles[4*i+1].color.a = (int)((1 - particles[i].life / lifetime_limit) * 120 + 135);
            quadrupled_particles[4*i+2].color.a = (int)((1 - particles[i].life / lifetime_limit) * 120 + 135);
            quadrupled_particles[4*i+3].color.a = (int)((1 - particles[i].life / lifetime_limit) * 120 + 135);
        }
    }

    void onDraw() const override {
        sf::RenderStates rs = sf::RenderStates(global_transform.getTransform());
        rs.texture = smoke_ptr.get();
        (*Layers::get_instance())[1]->draw(quadrupled_particles,rs);
    }

    
};