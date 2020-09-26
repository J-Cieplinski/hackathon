#include "Game.hpp"
#include <algorithm>

Game::Game()
    : window_(sf::VideoMode(windowWidth, windowHeight), "HackathonArkanoid") {
    window_.clear();
    window_.setFramerateLimit(60);
    background_ = std::make_shared<Background>();
    drawObjects_.push_back(background_);
}

void Game::run() {
    while (window_.isOpen()) {
        processWindowEvents();
        update();
        render();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;
        }
    }
}

void Game::addDrawObject(const std::shared_ptr<Entity>& drawable) {
    drawObjects_.push_back(drawable);
}

void Game::render() {
    window_.clear(sf::Color::White);
    for (const auto& obj : drawObjects_) {
        window_.draw(*obj);
    }
    window_.display();
}

void Game::processWindowEvents() {
    sf::Event event;

    while (window_.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window_.close();
            break;
        default:
            break;
        }
    }
}

void Game::removeDestroyedBricks() {
    drawObjects_.erase(std::remove_if(drawObjects_.begin(), drawObjects_.end(), [](const auto& el) { return el->isDestroyed_; }), drawObjects_.end());  //This doesn't free memory used by those bricks
}

void Game::update() {
    removeDestroyedBricks();
    std::for_each(drawObjects_.cbegin(), drawObjects_.cend(), [](const auto& obj) { obj->update(); });
}
