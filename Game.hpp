#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Headers.hpp"

class Game {
public:
    Game();
    void run();
    void addDrawObject(const std::shared_ptr<Entity>& drawable);  //for now, maybe not pointer but pure reference?

private:
    sf::RenderWindow window_;
    std::vector<std::shared_ptr<Entity>> drawObjects_{};

    void render();
    void update();
    void processWindowEvents();
};
