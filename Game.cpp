#include "Game.hpp"
#include <algorithm>
#include <iostream>
#include <typeinfo>

Game::Game() : window_(sf::VideoMode(windowWidth, windowHeight), "HackathonArkanoid") {
    window_.clear();
    window_.setFramerateLimit(60);
    background_ = std::make_shared<Background>();
    paddle_ = std::make_shared<Paddle>();
    player_ = std::make_shared<Player>(playerLives, playerPoints);
    ball_ = std::make_shared<Ball>(player_);

    bounceBuffer_.loadFromFile("../assets/sounds/bounce.wav");
    bounceSound_.setBuffer(bounceBuffer_);

    brickDestroyBuffer_.loadFromFile("../assets/sounds/brickDestruction.wav");
}

void Game::run() {
    while (window_.isOpen()) {
        processWindowEvents();
        update();
        render();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window_.close();
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
    drawObjects_.erase(
        std::remove_if(drawObjects_.begin(), drawObjects_.end(), [](const auto& el) { return el->isDestroyed_; }),
        drawObjects_.end());  // This doesn't free memory used by those bricks
    bricks.erase(std::remove_if(bricks.begin(), bricks.end(), [](const auto& el) { return el->isDestroyed_; }),
                 bricks.end());  // This doesn't free memory used by those bricks
}

void Game::update() {
    removeDestroyedBricks();
    std::for_each(drawObjects_.cbegin(), drawObjects_.cend(), [](const auto& obj) { obj->update(); });
    testCollision(ball_, paddle_);
    testCollision(ball_, bricks);
}

void Game::init() {
    for (int col = 0; col < blocksCol; ++col) {
        for (int row = 0; row < blocksRow; ++row) {
            bricks.push_back(std::make_shared<Brick>(((col + 1) * (blockWidth + blocksSpacing)) + blocksSpacing,
                                                     ((row + 1) * (blockHeight + blocksSpacing)) + spaceFromTop,
                                                     brickDestroyBuffer_));
        }
    }

    drawObjects_.push_back(background_);
    addDrawObject(paddle_);
    addDrawObject(ball_);
    addDrawObject(player_);
    for (auto& brick : bricks) {
        addDrawObject(brick);
    }
}

void Game::testCollision(std::shared_ptr<Ball>& ballPtr, std::shared_ptr<Paddle>& paddlePtr) {
    auto ball = ball_.get();
    auto paddle = paddle_.get();
    if (ball->getShape().getGlobalBounds().intersects(paddle->getShape().getGlobalBounds())) {
        bounceSound_.play();
        ball->reverseVelocityY();
        if (ball_->getX() < paddle->getX()) {
            ball->setVelocityX(-ballSpeed);
        } else {
            ball->setVelocityX(ballSpeed);
        }
    }
}

void Game::testCollision(std::shared_ptr<Ball>& ballPtr, std::vector<std::shared_ptr<Brick>>& bricks) {
    for (auto& element : bricks) {
        auto ball = ball_.get();
        auto brick = element.get();
        if (ball->getShape().getGlobalBounds().intersects(brick->getShape().getGlobalBounds())) {
            brick->destroyBrick();
            player_->addPoints();

            if (ball->getX() < brick->getLeft() || ball->getX() > brick->getRight()) {
                ball->reverseVelocityX();
            } else {
                ball->reverseVelocityY();
            }
        }
    }
}

void Game::ShowMenu() {
    // MainMenu menu(window_.getSize().x, window_.getSize().y);
    // sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

    MainMenu menu(window_.getSize().x, window_.getSize().y);

    while (window_.isOpen()) {
        sf::Event event;

        while (window_.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem()) {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        init();
                        run();
                        break;
                    case 1:
                        window_.close();
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window_.close();

                break;
            }
        }

        window_.clear();

        menu.draw(window_);

        window_.display();
    }
}
