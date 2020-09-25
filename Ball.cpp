#include "Ball.hpp"

Ball::Ball() {
    ball_.setPosition(windowWidth / 2, windowHeight / 2);
    ball_.setRadius(ballRadius);
    ball_.setFillColor(sf::Color::Red);
    ball_.setOrigin(ballRadius, ballRadius);
}

void Ball::move() {
    ball_.move(velocity_);  // something along those lines to move. Changing velocity vector (direction basically)
                            // through collision etc
    if (getLeft() < 0) {
        velocity_.x *= -1;
    } else if (getRight() > windowWidth) {
        velocity_.x *= -1;
    }

    if (getTop() < 0) {
        velocity_.y *= -1;
    } else if (getBottom() > windowHeight) {
        velocity_.y *= -1;
    }
}

void Ball::update() {  // everything that changes in regards to paddle, moving, changing color, etc
    move();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(ball_, states);
}

int Ball::getX() {
    return ball_.getPosition().x;
}
int Ball::getY() {
    return ball_.getPosition().y;
}
int Ball::getLeft() {
    return getX() - ball_.getRadius();
}
int Ball::getRight() {
    return getX() + ball_.getRadius();
}
int Ball::getTop() {
    return getY() - ball_.getRadius();
}
int Ball::getBottom() {
    return getY() + ball_.getRadius();
}
