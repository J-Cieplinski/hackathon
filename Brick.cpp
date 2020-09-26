#include "Brick.hpp"
#include "Headers.hpp"

Brick::Brick(float pos_x, float pos_y) {
    brick_.setSize(size_);
    brick_.setPosition(pos_x, pos_y);
    brick_.setFillColor(sf::Color::Blue);
    brick_.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
}

void Brick::update() {}  // everything that changes in regards to brick. Destroying, changing color etc.

void Brick::destroyBrick() {
    isDestroyed_ = true;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(brick_, states);
}

sf::RectangleShape Brick::getShape() {
    return brick_;
}

float Brick::getLeft() {
    return brick_.getPosition().x - brick_.getSize().x / 2.f;
}
float Brick::getRight() {
    return brick_.getPosition().x + brick_.getSize().x / 2.f;
}
