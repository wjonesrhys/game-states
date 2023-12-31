#include <gamestate.hpp>

GameState::GameState(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("other 1", true, sf::Vector2f(300, 250));
    menu.addItem("other 2", false, sf::Vector2f(300, 350));
    print("Game state created!");
}

GameState::~GameState() {
    print("Game state destroyed!");
}

void GameState::onEnter() {
    print("Game state loaded!");
}

void GameState::onExit() {
    print("Game state exited!");
}

void GameState::update() {
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                this->window.close();
                break;
            }
            if (event.key.code == sf::Keyboard::Up) {
                menu.moveUp();
                break;
            }
            if (event.key.code == sf::Keyboard::Down) {
                menu.moveDown();
                break;
            }
            if (event.key.code == sf::Keyboard::Enter) {
                if (menu.menuPressed() == 0) {
                    stateMachine.change("mainmenu");
                }
                break;
            }
        }
    }
}

void GameState::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}
