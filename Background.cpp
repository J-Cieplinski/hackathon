#include "Background.hpp"
#include <iostream>
#include "Headers.hpp"

Background::Background() {
    background_.setSize(sf::Vector2f(windowWidth, windowHeight));

    if (backgroundTexture.loadFromFile("../assets/background.png")) {
        background_.setTexture(&backgroundTexture);
    }
}
void Background::update(){};

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background_, states);
};