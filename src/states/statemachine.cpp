#include "statemachine.hpp"

StateMachine::StateMachine() {
    // states = map<string, string>();
    print("no function definition set up");
}

StateMachine::~StateMachine() {
    print("State Machine destroyed.");
}

void StateMachine::update() {
    print("no function definition set up");
}

void StateMachine::render() {
    print("no function definition set up");
}

void StateMachine::change() {
    print("no function definition set up");
}

void StateMachine::add(string key, string value) {
    states[key] = value;
    print("no function definition set up");
}

void StateMachine::printStates() {
    map<string, string>::iterator it = states.begin();

    while (it != states.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
}