#pragma once
#include <iostream>
#include "util.hpp"
#include "application.hpp"
#include "statemachine.hpp"
#include "SFML/Graphics.hpp"

class Application {
    private:
        sf::RenderWindow &window;
        // StateMachine stateMachine;

    public:
        Application(sf::RenderWindow &renderWindow);
        ~Application();

        void start();
};