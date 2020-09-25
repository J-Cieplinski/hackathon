#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
public:
    virtual void update() = 0;
    virtual ~Entity() = default;
};
