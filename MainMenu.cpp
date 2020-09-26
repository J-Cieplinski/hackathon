#include "MainMenu.hpp"
#include <iostream>

constexpr size_t startMenu = 0;
constexpr size_t exitMenu = 1;

constexpr size_t buttonWidth = 120;
constexpr size_t buttonHeight = 60;

MainMenu::MainMenu() {
    if (!font_.loadFromFile("../assets/fonts/Retronoid.ttf")) {
        std::cout << "cant read font \n";
    }
    title_.setFont(font_);
    title_.setString("Arkanoid Hackathon");
    title_.setCharacterSize(60);
    title_.setFillColor(sf::Color(136, 216, 152));
    title_.setPosition(sf::Vector2f(windowWidth / 2 - 320, windowHeight / 4));

    menuStart_.loadFromFile("../assets/textures/play.png");
    menuExit_.loadFromFile("../assets/textures/exit.png");
    backgroundTexture_.loadFromFile("../assets/textures/mainmenu.png");

    background_.setSize(sf::Vector2f(windowWidth, windowHeight));
    background_.setTexture(&backgroundTexture_);

    menu_[startMenu].setTexture(&menuStart_);
    menu_[startMenu].setFillColor(sf::Color::Red);
    menu_[startMenu].setSize(sf::Vector2f(buttonWidth, buttonHeight));
    menu_[startMenu].setPosition(sf::Vector2f(windowWidth / 2 - buttonWidth / 2, windowHeight * 0.60));

    menu_[exitMenu].setTexture(&menuExit_);
    menu_[exitMenu].setSize(sf::Vector2f(buttonWidth, buttonHeight));
    menu_[exitMenu].setPosition(sf::Vector2f(windowWidth / 2 - buttonWidth / 2, windowHeight * 0.75));

    itemIndex_ = 0;
}

MainMenu::~MainMenu() {}

void MainMenu::drawMenu(sf::RenderWindow& window) {
    window.draw(background_);
    for (int i = 0; i < menuItems; i++) {
        window.draw(menu_[i]);
    }
    window.draw(title_);
}

void MainMenu::MoveUp() {
    if (itemIndex_ - 1 >= 0) {
        menu_[itemIndex_].setFillColor(sf::Color::White);
        itemIndex_--;
        menu_[itemIndex_].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown() {
    if (itemIndex_ + 1 < menuItems) {
        menu_[itemIndex_].setFillColor(sf::Color::White);
        itemIndex_++;
        menu_[itemIndex_].setFillColor(sf::Color::Red);
    }
}

int MainMenu::getCurrentIndex() {
    return itemIndex_;
}
