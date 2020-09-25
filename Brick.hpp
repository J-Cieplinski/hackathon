#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Brick : public Entity {
private:
    Brick();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape brick_;
};
