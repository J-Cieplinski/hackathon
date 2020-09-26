#pragma once

#include "Entity.hpp"
#include "Headers.hpp"
#include "SFML/Graphics.hpp"

class GameOver : public Entity {
public:
    GameOver();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape gameOver_;
    sf::Texture gameOverTexture_;
    sf::Vector2f gameOverSpeed_{0, -2.5f};
};