#include "game.hpp"
#include "mainmenustate.hpp"
#include "playstate.hpp"

#include "examplestate1.hpp"
#include "examplestate2.hpp"
#include "examplestate3.hpp"


Game::Game(sf::RenderWindow& renderWindow) : window(renderWindow) {
    //add statemachine instantiation here and in header file
    print("Game Created");
}

Game::~Game() {
    print("Game Closed");
}

void Game::start()
{
    StateMachine stateMachine;    
    // stateMachine.add("mainmenu", new MainMenuState(this->window, stateMachine));
    // stateMachine.add("play", new PlayState(this->window, stateMachine));
    // stateMachine.change("mainmenu");

    stateMachine.push(new ExampleState1(this->window, stateMachine));
    stateMachine.push(new ExampleState2(this->window, stateMachine));
    stateMachine.push(new ExampleState3(this->window, stateMachine));

    stateMachine.printStates();

    // std::cout << "MainMenuStates: " << MainMenuState::getCounter() << std::endl;
    // stateMachine.~StateMachine();
    // std::cout << "MainMenuStates: " << MainMenuState::getCounter() << std::endl;
    
    while (this->window.isOpen())
    {
        this->window.clear();
        // stateMachine.update();
        // stateMachine.render();
        stateMachine.updateStack();
        stateMachine.renderStack();
        this->window.display();
    }
}