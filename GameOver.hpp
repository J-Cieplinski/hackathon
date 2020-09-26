#pragma once

#include <SFML/Audio.hpp>
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

    sf::SoundBuffer gameOverBuffer_;
    sf::Sound gameOverSound_;
};
