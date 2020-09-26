#include "Ball.hpp"

Ball::Ball() {
    ball_.setPosition(windowWidth / 2, windowHeight / 2);
    ball_.setRadius(ballRadius);
    ball_.setFillColor(sf::Color::Red);
    ball_.setOrigin(10, 10);
}

void Ball::move() {
    ball_.move(velocity_);

    if (getLeft() < sidesBoundries) {
        reverseVelocityX();
    } else if (getRight() > windowWidth - sidesBoundries) {
        reverseVelocityX();
    }

    if (getTop() < topBoundry) {
        reverseVelocityY();
    } else if (getBottom() > windowHeight) {
        ball_.setPosition(windowWidth / 2, windowHeight / 2);
    }
}

void Ball::update() {
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

void Ball::setVelocityX(float xSpeed) {
    velocity_.x = xSpeed;
};

void Ball::setVelocityY(float ySpeed) {
    velocity_.y = ySpeed;
};

sf::CircleShape& Ball::getShape() {
    return ball_;
}
