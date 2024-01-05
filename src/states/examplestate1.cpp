#include <examplestate1.hpp>
#include <examplestate2.hpp>

// int ExampleState1::count = 0;

ExampleState1::ExampleState1(sf::RenderWindow& renderWindow, StateMachine& stateMachine) : window(renderWindow), stateMachine(stateMachine){
    menu.addItem("hi 1", true, sf::Vector2f(300, 250));
    menu.addItem("hihi", false, sf::Vector2f(300, 350));
    menu.addItem("hihihi", false, sf::Vector2f(300, 450));
    menu.addItem("hihihihi", false, sf::Vector2f(300, 550));
    print("Example state 1 state created!");
}

ExampleState1::~ExampleState1() {
    print("Example state 1 destroyed!");
    // count--;
}

void ExampleState1::onEnter() {
    print("Example state 1 loaded!");
    menu.colourMenuSelected();
}

void ExampleState1::onExit() {
    print("Example state 1 exited!");
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
                        stateMachine.push(new ExampleState2(this->window, stateMachine));
                        break;
                    case 1:
                        // stateMachine.pop();
                        break;
                    case 2:
                        menu.clearColouredText();
                        menu.colourMenuSelected();
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
