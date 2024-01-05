#include <examplestate2.hpp>
#include <examplestate3.hpp>

// int ExampleState2::count = 0;

ExampleState2::ExampleState2(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("hi 2", true, sf::Vector2f(300, 250));
    menu.addItem("hihi", false, sf::Vector2f(300, 350));
    menu.addItem("hihihi", false, sf::Vector2f(300, 450));
    menu.addItem("hihihihi", false, sf::Vector2f(300, 550));
    print("Example state 2 state created!");
}

ExampleState2::~ExampleState2() {
    print("Example state 2 destroyed!");
    // count--;
}

void ExampleState2::onEnter() {
    print("Example state 2 loaded!");
    menu.colourMenuSelected();
}

void ExampleState2::onExit() {
    print("Example state 2 exited!");
}

void ExampleState2::update() {
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
                switch (menu.menuPressed()) {
                    case 0:
                        stateMachine.push(new ExampleState3(this->window, stateMachine));
                        break;
                    case 1:
                        stateMachine.pop();
                        break;
                    default:
                        print("nothing happened");
                }
            }
        }
    }


}

void ExampleState2::render() {
    for (sf::Text text : menu.getItems()) {
        window.draw(text);
    }
}

// int ExampleState2::getCounter() {
//     return count;
// }
