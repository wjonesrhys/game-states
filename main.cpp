#include <iostream>
#include "game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ping Pong");
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");

    srand(time(nullptr));
    Game game = Game(window);
    
    // Start the game loop
    game.start();

    return 0;
}