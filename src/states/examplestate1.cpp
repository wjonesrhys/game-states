#include <ExampleState1.hpp>

// int ExampleState1::count = 0;

ExampleState1::ExampleState1(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("Example State 1", true, sf::Vector2f(300, 250));
}

ExampleState1::~ExampleState1() {
    print("Main menu destroyed!");
    // count--;
}

void ExampleState1::onEnter() {
    print("Main menu loaded!");
}

void ExampleState1::onExit() {
    print("Main menu exited!");
}

void ExampleState1::update() {
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
                        stateMachine.change("play");
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }


}

void ExampleState1::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}

// int ExampleState1::getCounter() {
//     return count;
// }
