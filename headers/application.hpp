#pragma once
#include <vector>

#include "statemachine.hpp"

class Application {
    private:
        sf::RenderWindow &window;
        // StateMachine stateMachine;

    public:
        Application(sf::RenderWindow &renderWindow);
        ~Application();

        void start();
};