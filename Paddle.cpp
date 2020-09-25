#include "Paddle.hpp"
#include "Headers.hpp"

Paddle::Paddle() {
    paddle_.setSize(paddleSize_);
    paddle_.setPosition(paddlePosition_);
    paddle_.setFillColor(sf::Color::Red);
}

void Paddle::moveLeft() {
    auto positionAfterMovement = paddlePosition_ + leftVelocity_;

    if (positionAfterMovement.x < 0) {
        paddlePosition_.x = 0;
    } else {
        paddlePosition_ += leftVelocity_;
    }
    paddle_.setPosition(paddlePosition_);
}

void Paddle::moveRight() {
    auto positionAfterMovement = paddlePosition_ + rightVelocity_ + paddleSize_;

    if (positionAfterMovement.x > windowWidth) {
        paddlePosition_.x = windowWidth - paddleSize_.x;
    } else {
        paddlePosition_ += rightVelocity_;
    }

    paddle_.setPosition(paddlePosition_);
}

void Paddle::move() {
    if (sf::Keyboard::isKeyPressed(Keys::left)) {
        moveLeft();
    } else if (sf::Keyboard::isKeyPressed(Keys::right)) {
        moveRight();
    }
}

void Paddle::update() {  //everything that changes in regards to paddle, moving, changing color, etc
    move();
    paddlePosition_ = paddle_.getPosition();
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(paddle_, states);
}
