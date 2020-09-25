#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

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

private:
    sf::RectangleShape paddle_;
    sf::Vector2f leftVelocity_{-1.5f, 0.f};
    sf::Vector2f rightVelocity_{1.5f, 0.f};

    sf::Vector2f position_{};
    sf::Vector2f size_{120.f, 15.f};
};
