#include <playstate.hpp>

PlayState::PlayState(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("other 1", true, sf::Vector2f(300, 250));
    menu.addItem("other 2", false, sf::Vector2f(300, 350));
    print("Game state created!");
}

PlayState::~PlayState() {
    print("Game state destroyed!");
}

void PlayState::onEnter() {
    print("Game state loaded!");
}

void PlayState::onExit() {
    print("Game state exited!");
}

void PlayState::update() {
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
                print(menu.menuPressed());
                switch (menu.menuPressed()) {
                    case 0:
                        stateMachine.change("mainmenu");
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }
}

void PlayState::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}
