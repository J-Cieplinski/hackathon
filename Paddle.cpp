#include "Paddle.hpp"
#include "Headers.hpp"

Paddle::Paddle() {
    paddle_.setSize(size_);
    sf::Vector2f screenCenter{windowWidth / 2 - size_.x / 2, windowHeight - size_.y};
    paddle_.setPosition(screenCenter);
    paddle_.setFillColor(sf::Color::Red);
}

void Paddle::move() {
    if (sf::Keyboard::isKeyPressed(Keys::left)) {
        paddle_.move(leftVelocity_);
    } else if (sf::Keyboard::isKeyPressed(Keys::right)) {
        paddle_.move(rightVelocity_);
    }
}

void Paddle::update() {  //everything that changes in regards to paddle, moving, changing color, etc
    move();
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(paddle_, states);
}
