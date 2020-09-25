#include "Ball.hpp"
#include "Game.hpp"
#include "Paddle.hpp"

int main() {
    auto paddle = std::make_shared<Paddle>();
    auto ball = std::make_shared<Ball>();
    Game game;
    game.addDrawObject(paddle);
    game.addDrawObject(ball);
    game.run();
}
