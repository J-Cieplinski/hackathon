#include "Game.hpp"
#include "Paddle.hpp"

int main() {
    auto paddle = std::make_shared<Paddle>();
    Game game;
    game.addDrawObject(paddle);
    game.run();
}