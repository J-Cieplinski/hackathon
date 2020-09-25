#include "Brick.hpp"
#include "Ball.hpp"
#include "Game.hpp"
#include "Paddle.hpp"

int main() {
    auto paddle = std::make_shared<Paddle>();

    std::vector<std::shared_ptr<Brick>> bricks;

    for (int col = 0; col < blocksCol; col++) {
        for (int row = 0; row < blocksRow; row++) {
            bricks.push_back(std::make_shared<Brick>((col * (blockWidth + spaceBetweenBlocks)) + spaceBetweenBlocks,
                                                     (row * (blockHeight + spaceBetweenBlocks)) + spaceFromTop));
        }
    }
    
    Game game;
    game.addDrawObject(paddle);
    for (auto brick : bricks) {
        game.addDrawObject(brick);
    }
    auto ball = std::make_shared<Ball>();
    game.addDrawObject(ball);
    game.run();
}
