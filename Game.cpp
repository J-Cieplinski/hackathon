#include "Game.hpp"
#include <algorithm>

Game::Game()
    : window_(sf::VideoMode(windowWidth, windowHeight), "HackathonArkanoid") {
    window_.clear();
    window_.setFramerateLimit(60);
}

void Game::run() {
    while (window_.isOpen()) {
        processWindowEvents();
        update();
        render();
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

void Game::update() {
    std::for_each(drawObjects_.cbegin(), drawObjects_.cend(), [](const auto& obj) { obj->update(); });
}