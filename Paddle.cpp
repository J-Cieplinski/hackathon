#include "Paddle.hpp"
#include "Headers.hpp"

Paddle::Paddle() {
    paddle_.setSize(size_);
    paddle_.setPosition(windowWidth / 2, windowHeight / 2);
    paddle_.setFillColor(sf::Color::Red);
}

void Paddle::move() {
    paddle_.move(velocity_);  //something along those lines to move. Changing velocity vector (direction basically) through user input etc
}

void Paddle::update() {  //everything that changes in regards to paddle, moving, changing color, etc
    move();
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(paddle_, states);
}
