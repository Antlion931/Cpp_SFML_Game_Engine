#pragma once
#include <SFML/Graphics.hpp>

sf::Transformable combineTransforms(const sf::Transformable &parent, const sf::Transformable &child)
{
	sf::Transformable result;
	result.setScale({parent.getScale().x*child.getScale().x,parent.getScale().y*child.getScale().y});
	result.setRotation(parent.getRotation() + child.getRotation());
	result.setPosition(parent.getTransform() * child.getPosition());
	return result;
}