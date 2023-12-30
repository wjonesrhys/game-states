#include "application.hpp"

Application::Application(sf::RenderWindow& renderWindow) : window(renderWindow) {
    //add statemachine instantiation here and in header file
}

Application::~Application() {
    std::cout << "Application Closed";
}

void Application::start()
{
    StateMachine stateMachine;
    stateMachine.add("Play", "Hello");
    stateMachine.add("Options", "Hello");
    stateMachine.add("About", "Hello");
    stateMachine.add("Exit", "Goodbye");
    stateMachine.add("Main Menu", "Goodbye");
    stateMachine.add("Pause Menu", "Goodbye");

    //set the main menu as the first state
    //use a queue stack system to go back if you exit or finish the game
    //check if a flag is set within a state
    while (this->window.isOpen())
    {
        // sf::RenderWindow newwindow();


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
        stateMachine.printStates();
        // stateMachine.update();
        // stateMachine.render();
        this->window.display();
    }
}