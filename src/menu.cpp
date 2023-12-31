#include <menu.hpp>
#include <util.hpp>

Menu::Menu() {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "not loaded";
    }
    setMenuSelected(-1);
}

Menu::~Menu() {

}

std::vector<sf::Text> Menu::getItems() {
    return this->menuItems;
}

void Menu::addItem(std::string text, bool isOn, sf::Vector2f position) {
    sf::Text menuText;
    isOn ? menuText.setFillColor(sf::Color::Blue) : menuText.setFillColor(sf::Color::White);
    menuText.setFont(font);
    menuText.setString(text);
    menuText.setCharacterSize(70);
    menuText.setPosition(position);
    menuItems.push_back(menuText);
}

void Menu::moveUp() {
    if (menuSelected - 1 >=-1) {
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuSelected--;
    if (menuSelected == -1) {
        menuSelected=menuItems.size()-1;
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }
    menuItems.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::moveDown() {
    if (menuSelected + 1 <=menuItems.size()) {
        menuItems.at(menuSelected).setFillColor(sf::Color::White);
    }    
    menuSelected++;
    if (menuSelected == menuItems.size()) {
        menuSelected=0;
    }
    menuItems.at(menuSelected).setFillColor(sf::Color::Blue);
}

int Menu::menuPressed() {
    return menuSelected;
}

void Menu::setMenuSelected(int index) {
    menuSelected = 0;
}