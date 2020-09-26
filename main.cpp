#include <chrono>
#include <thread>
#include "Headers.hpp"

int main() {
    Game game;
    game.ShowMenu();
    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // game.init();
    game.run();
    return 0;
}
