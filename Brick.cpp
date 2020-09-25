#include "Brick.hpp"

Brick::Brick() {
}

void Brick::update() {  //everything that changes in regards to brick. Destroying, changing color etc.
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= brick_.getTransform();
    target.draw(brick_, states);
}