#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Headers.hpp"

class Ball;
class Paddle;
class Brick;
class Game {
public:
    Game();
    void run();
    void init();
    void removeDestroyedBricks();
    void addDrawObject(const std::shared_ptr<Entity>& drawable);  // for now, maybe not pointer but pure reference?
    void testCollision(std::shared_ptr<Ball>& ballPtr, std::shared_ptr<Paddle>& paddlePtr);
    void testCollision(std::shared_ptr<Ball>& ballPtr, std::vector<std::shared_ptr<Brick>>& bricks);

private:
    sf::RenderWindow window_;
    std::vector<std::shared_ptr<Entity>> drawObjects_{};

    void render();
    void update();
    void processWindowEvents();
    std::shared_ptr<Ball> ball_;
    std::shared_ptr<Paddle> paddle_;
    std::vector<std::shared_ptr<Brick>> bricks;
};
