#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Headers.hpp"

class Ball : public Entity {
public:
    Ball();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void move();
    int getX();
    int getY();
    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
    float getVelocityX();
    float getVelocityY();
    void setVelocityX(float xSpeed);
    void setVelocityY(float ySpeed);
    void reverseVelocityX();
    void reverseVelocityY();
    const sf::CircleShape& getShape();

private:
    sf::CircleShape ball_;
    sf::Texture ballTexture_;

    sf::Vector2f velocity_{ballSpeed, -ballSpeed};
};
