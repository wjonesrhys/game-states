#include "game.hpp"
#include "mainmenustate.hpp"
#include "playstate.hpp"

Game::Game(sf::RenderWindow& renderWindow) : window(renderWindow) {
    //add statemachine instantiation here and in header file
    print("Application Created");
}

Game::~Game() {
    print("Application Closed");
}

void Game::start()
{
    StateMachine stateMachine;    
    stateMachine.add("mainmenu", new MainMenuState(this->window, stateMachine));
    stateMachine.add("play", new PlayState(this->window, stateMachine));
    stateMachine.change("mainmenu");

    stateMachine.printStates();

    // std::cout << "MainMenuStates: " << MainMenuState::getCounter() << std::endl;
    // stateMachine.~StateMachine();
    // std::cout << "MainMenuStates: " << MainMenuState::getCounter() << std::endl;
    
    while (this->window.isOpen())
    {
        this->window.clear();
        stateMachine.update();
        stateMachine.render();
        this->window.display();
    }
}