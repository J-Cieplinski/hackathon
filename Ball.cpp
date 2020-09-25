#include "Ball.hpp"

Ball::Ball() {
}

void Ball::move() {
    ball_.move(velocity_);  //something along those lines to move. Changing velocity vector (direction basically) through collision etc
}

void Ball::update() {  //everything that changes in regards to paddle, moving, changing color, etc
    move();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= ball_.getTransform();
    target.draw(ball_, states);
}
