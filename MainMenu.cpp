#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("../assets/fonts/PWStrokes.ttf")) {
        std::cout << "cant read font \n";
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play!");
    menu[0].setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 4));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 2));

    selectedItemIndex = 0;
}

MainMenu::~MainMenu() {}

void MainMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 2; i++) {
        window.draw(menu[i]);
    }
}

void MainMenu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown() {
    if (selectedItemIndex + 1 < 2) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
