#pragma once
#include "SFML/Graphics.hpp"
#include "state.hpp"
#include <vector>

class Game {
    private:
        sf::RenderWindow &window;
        State* currentState;

    public:
        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void startGame();
        void drawGame();

        void changeState(State* state);
};