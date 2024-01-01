#pragma once
#include <iostream>
#include "util.hpp"
#include "SFML/Graphics.hpp"

class Game {
    private:
        sf::RenderWindow &window;

    public:
        Game(sf::RenderWindow &renderWindow);
        ~Game();

        void start();
};