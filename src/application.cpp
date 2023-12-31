#include "application.hpp"
#include "mainmenustate.hpp"
#include "gamestate.hpp"

Application::Application(sf::RenderWindow& renderWindow) : window(renderWindow) {
    //add statemachine instantiation here and in header file
    print("Application Created");
}

Application::~Application() {
    print("Application Closed");
}

void Application::start()
{
    StateMachine stateMachine;    
    stateMachine.add("mainmenu", new MainMenuState(this->window, stateMachine));
    stateMachine.add("game", new GameState(this->window, stateMachine));
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