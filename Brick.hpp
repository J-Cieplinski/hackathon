#pragma once

#include <SFML/Graphics.hpp>
#include "Headers.hpp"

class Brick : public Entity {
public:
    Brick(float pos_x, float pos_y);
    void destroyBrick();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    const sf::RectangleShape& getShape();
    float getLeft();
    float getRight();

private:
    sf::RectangleShape brick_;
    sf::Vector2f position_{};
    sf::Vector2f size_{blockWidth, blockHeight};
};
