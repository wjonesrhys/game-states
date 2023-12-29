#include <iostream>
#include "application.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ping Pong");
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");

    srand(time(nullptr));
    Application application = Application(window);
    
    // Start the game loop
    application.start();

    return 0;
}