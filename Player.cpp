#include "Player.hpp"
#include <iostream>

Player::Player(int lives, int points) : lives_(lives), points_(points) {
    if (!font_.loadFromFile("../assets/fonts/PWStrokes.ttf")) {
        // error...
        std::cout << "cant read font \n";
    }
    text_.setFont(font_);

    text_.setString("Lives: " + std::to_string(lives_) + "   Points: " + std::to_string(points_));
    // text_.setString();
    // text_.setString("Points: ");
    // text_.setString(std::to_string(playerPoints));
    text_.setCharacterSize(22);
    text_.setFillColor(sf::Color::Red);
    text_.setPosition(70, 25);
}

void Player::update() {  // everything that changes in regards to paddle, moving, changing color, etc
    text_.setString("Lives: " + std::to_string(lives_) + "   Points: " + std::to_string(points_));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text_, states);
}