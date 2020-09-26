#include "GameOver.hpp"

GameOver::GameOver() {
    gameOverTexture_.loadFromFile("../assets/textures/GameOver.png");
    gameOver_.setTexture(&gameOverTexture_);
    gameOver_.setSize(sf::Vector2f(gameOverX, gameOverY));
    gameOver_.setPosition(sf::Vector2f(windowWidth / 2 - gameOverX / 2, windowHeight + gameOverY));

    gameOverBuffer_.loadFromFile("../assets/sounds/gameOverMusic.wav");
    gameOverSound_.setBuffer(gameOverBuffer_);
}

void GameOver::update() {
    if (gameOver_.getPosition().y >= windowHeight / 2) {
        gameOverSound_.play();
        gameOver_.move(gameOverSpeed_);
    }
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(gameOver_, states);
}
