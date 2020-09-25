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
    sf::Vector2f velocity_{};
    sf::Vector2f position_{};
    sf::Vector2f size_{30.f, 30.f};
};
