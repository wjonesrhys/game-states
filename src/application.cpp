#include <iostream>
#include <string>
#include <vector>
#include <application.hpp>
#include <gamestate.hpp>
#include <util.hpp>

#include "SFML/Graphics.hpp"

Application::Application(sf::RenderWindow& renderWindow) : window(renderWindow) {
    //add statemachine instantiation here and in header file
}

Application::~Application() {
    std::cout << "Game Closed";
}

void Application::start()
{
    //set the main menu as the first state
    //use a queue stack system to go back if you exit or finish the game
    //check if a flag is set within a state
    while (this->window.isOpen())
    {
        // sf::RenderWindow newwindow();
        // GameState gameState = GameState();
        // gameState.onEnter();

        sf::Event event;
        
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                this->window.close();
            }
        }
        this->window.clear();
        // stateMachine.update();
        // stateMachine.render();
        this->window.display();
    }
}