#pragma once

#include "Headers.hpp"
#include "SFML/Graphics.hpp"

class MainMenu {
public:
    MainMenu();
    ~MainMenu();

    void drawMenu(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int getCurrentIndex();

private:
    int itemIndex;
    sf::Font font;
    sf::Text menu[menuItems];
};
