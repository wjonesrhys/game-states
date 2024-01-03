#include <examplestate3.hpp>

// int ExampleState3::count = 0;

ExampleState3::ExampleState3(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("Example State 3", true, sf::Vector2f(300, 250));
    print("Main menu state created!");
    // count++;
}

ExampleState3::~ExampleState3() {
    print("Main menu destroyed!");
    // count--;
}

void ExampleState3::onEnter() {
    print("Main menu loaded!");
}

void ExampleState3::onExit() {
    print("Main menu exited!");
}

void ExampleState3::update() {
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

void ExampleState3::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}

// int ExampleState3::getCounter() {
//     return count;
// }
