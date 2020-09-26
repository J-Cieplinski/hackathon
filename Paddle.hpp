#pragma once

#include <SFML/Graphics.hpp>
#include "Headers.hpp"

struct Keys {
    inline static auto left = sf::Keyboard::Left;
    inline static auto right = sf::Keyboard::Right;
};

class Paddle : public Entity {
public:
    Paddle();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void move();  
    int getX();
    float getLeft();
    float getRight();
    const sf::RectangleShape& getShape();

private:
    void moveLeft();
    void moveRight();

    sf::RectangleShape paddle_;
    sf::Vector2f velocity_{0, 0};
    sf::Texture paddleTexture_;
    sf::Vector2f leftVelocity_{-paddleSpeed, 0.f};
    sf::Vector2f rightVelocity_{paddleSpeed, 0.f};

    sf::Vector2f paddleSize_{120.f, 15.f};
    sf::Vector2f paddlePosition_{windowWidth / 2 - paddleSize_.x / 2, windowHeight - paddleSize_.y};
};
