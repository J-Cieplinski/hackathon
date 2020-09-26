#pragma once

#include "Headers.hpp"
#include "SFML/Graphics.hpp"

class MainMenu {
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[2];
};
