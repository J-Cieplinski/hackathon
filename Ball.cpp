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
        reverseVelocityX();
    } else if (getRight() > windowWidth) {
        reverseVelocityX();
    }

    if (getTop() < 0) {
        reverseVelocityY();
    } else if (getBottom() > windowHeight) {
        reverseVelocityY();
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

float Ball::getVelocityX() {
    return velocity_.x;
};

float Ball::getVelocityY() {
    return velocity_.y;
};

void Ball::reverseVelocityX() {
    velocity_.x *= -1;
};

void Ball::reverseVelocityY() {
    velocity_.y *= -1;
};

sf::CircleShape Ball::getShape() {
    return ball_;
}
