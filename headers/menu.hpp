#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Menu {
    private:
        sf::Font font;
        int menuSelected;        
        std::vector<sf::Text> menuItems;

    public:
        Menu();
        ~Menu();

        std::vector<sf::Text> getItems();
        void addItem(std::string text, bool isOn, sf::Vector2f position);

        void moveUp();
        void moveDown();

        int menuPressed();
        void setMenuSelected(int index);
};