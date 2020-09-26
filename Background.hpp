#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Background : public Entity {
public:
    Background();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape background_;
    sf::Texture backgroundTexture;
};