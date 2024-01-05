#include <menu.hpp>
#include <util.hpp>

Menu::Menu() {
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cout << "not loaded";
    }
    setMenuSelected(0);
}

Menu::~Menu() {

}

std::vector<sf::Text> Menu::getItems() {
    return this->menuItems;
}

void Menu::addItem(std::string text, bool isOn, sf::Vector2f position) {
    sf::Text menuText;
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
    print("menu number selected: " + menuSelected);
    return menuSelected;
}

void Menu::clearColouredText() {
    for (sf::Text text : menuItems) {
        text.setFillColor(sf::Color::White);
    }
}

void Menu::colourMenuSelected() {
    this->menuItems.at(menuSelected).setFillColor(sf::Color::Blue);
}

void Menu::setMenuSelected(int index) {
    menuSelected = index;
    if (menuItems.size() > 0) {
        clearColouredText();    
        colourMenuSelected();   
    }
}