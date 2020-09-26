#pragma once

#include <SFML/Graphics.hpp>
#include "Headers.hpp"

class Player : public Entity {
public:
    Player();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Player(int lives, int points);
    void addPoints();
    void removeLives();

private:
    int lives_;
    int points_;
    sf::Text text_;
    sf::Font font_;
};
