#include "Paddle.hpp"
#include "Headers.hpp"

Paddle::Paddle() {
    paddleTexture_.loadFromFile("../assets/Paddle.png");
    paddle_.setSize(paddleSize_);
    paddle_.setPosition(paddlePosition_);
    paddle_.setTexture(&paddleTexture_);
    paddle_.setOrigin(paddleSize_.x / 2.f, paddleSize_.y / 2.f);
}

void Paddle::move() {
    paddle_.move(velocity_);  // something along those lines to move. Changing velocity vector (direction basically)
                              // through collision etc
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeft() > sidesBoundries) {
        velocity_.x = -paddleSpeed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRight() < windowWidth - sidesBoundries) {
        velocity_.x = paddleSpeed;
    } else {
        velocity_.x = 0;
    }
}

void Paddle::update() {  // everything that changes in regards to paddle, moving, changing color, etc
    move();
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(paddle_, states);
}

int Paddle::getX() {
    return paddle_.getPosition().x;
}

float Paddle::getLeft() {
    return getX() - paddle_.getSize().x / 2.f;
}
float Paddle::getRight() {
    return getX() + paddle_.getSize().x / 2.f;
}

const sf::RectangleShape& Paddle::getShape() {
    return paddle_;
}
