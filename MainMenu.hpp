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
    int itemIndex_;
    sf::Font font_;
    sf::Text title_;
    sf::RectangleShape menu_[menuItems];
    sf::RectangleShape background_;
    sf::Texture menuStart_;
    sf::Texture menuExit_;
    sf::Texture backgroundTexture_;
};
