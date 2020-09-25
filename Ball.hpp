#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Ball : public Entity {
public:
    Ball();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void move();

private:
    sf::RectangleShape ball_;
    sf::Vector2f velocity_{};
    sf::Vector2f position_{};
};
