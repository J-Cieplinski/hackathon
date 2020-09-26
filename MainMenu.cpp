#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu() {
    if (!font.loadFromFile("../assets/fonts/Retronoid.ttf")) {
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

    itemIndex = 0;
}

MainMenu::~MainMenu() {}

void MainMenu::drawMenu(sf::RenderWindow& window) {
    for (int i = 0; i < menuItems; i++) {
        window.draw(menu[i]);
    }
}

void MainMenu::MoveUp() {
    if (itemIndex - 1 >= 0) {
        menu[itemIndex].setFillColor(sf::Color::White);
        itemIndex--;
        menu[itemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown() {
    if (itemIndex + 1 < menuItems) {
        menu[itemIndex].setFillColor(sf::Color::White);
        itemIndex++;
        menu[itemIndex].setFillColor(sf::Color::Red);
    }
}

int MainMenu::getCurrentIndex() {
    return itemIndex;
}
