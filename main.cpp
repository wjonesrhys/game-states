#include <iostream>
#include "headers/game.hpp"
#include "headers/mainmenustate.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ping Pong");
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping Pong");

    srand(time(nullptr));
    Game game = Game(window);

    // Initialize the game with a specific GameState (e.g., MainMenuState)
    State* initialState = new MainMenuState(&game);
    game.changeState(initialState);
    
    // Start the game loop
    game.startGame();

    // Clean up resources and memory
    delete initialState;

    return 0;
}