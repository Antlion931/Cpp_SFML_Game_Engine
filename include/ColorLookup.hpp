#pragma once
#include "Nodes/Node.hpp"

class ColorLookup
{
public:
    static ColorLookup* get_instance();

private:
    static ColorLookup* m_instance;

    std::unordered_map<sf::Color, std::weak_ptr<Node>> m_color_map;
    std::unordered_map<sf::Color, EventEmitter<>> on_hover;
    std::unordered_map<sf::Color, EventEmitter<>> on_click;
    std::unordered_map<sf::Color, EventEmitter<>> on_train_hit;

public:
    void register_ptr(sf::Color color, std::weak_ptr<Node> ptr) {
        m_color_map[color] = ptr;
    }
    void register_hover(sf::Color color, EventListener<> listener) {
        EventEmitter<> ee;
        ee.subscribe(listener);
        on_hover[color] = ee;
    }
    void register_click(sf::Color color, EventListener<> listener) {
        EventEmitter<> ee;
        ee.subscribe(listener);
        on_click[color] = ee;
    }
    void register_train_hit(sf::Color color, EventListener<> listener) {
        EventEmitter<> ee;
        ee.subscribe(listener);
        on_train_hit[color] = ee;
    }

    std::weak_ptr<Node> read_ptr(sf::Color color) {
        return m_color_map[color];
    }
    void emit_hover(sf::Color color) {
        on_hover[color].emit();
    }
    void emit_click(sf::Color color) {
        on_click[color].emit();
    }
    void emit_train_hit(sf::Color color) {
        on_train_hit[color].emit();
    }
};