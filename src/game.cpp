#include <iostream>
#include <string>
#include <vector>
#include <game.hpp>
#include <gamestate.hpp>
#include <util.hpp>

#include "SFML/Graphics.hpp"

Game::Game(sf::RenderWindow& renderWindow) : window(renderWindow) {

}

Game::~Game() {
    std::cout << "Game Closed";
}

void Game::changeState(State* state) {
    currentState = new GameState();
}


void Game::drawGame() {
    sf::CircleShape shape(100.f);
    shape.setPosition(window.getSize().x/2, window.getSize().y/2);
    shape.setFillColor(sf::Color::Green);
    this->window.draw(shape);
}

void Game::startGame()
{
    //set the main menu as the first state
    //use a queue stack system to go back if you exit or finish the game
    //check if a flag is set within a state
    while (this->window.isOpen())
    {
        // sf::RenderWindow newwindow();
        GameState gameState = GameState();
        gameState.enter();
        gameState.enter();
        gameState.enter();
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
        drawGame();
        this->window.display();
    }
}