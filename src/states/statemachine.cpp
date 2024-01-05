#include "statemachine.hpp"

StateMachine::StateMachine() {
    print("State Machine created.");
}

StateMachine::~StateMachine() {
    unordered_map<std::string, State*>::iterator it = states.begin();
    while (it != states.end()) {
        std::cout << it->first << std::endl;
        delete it->second;
        ++it;
    }
    print("State Machine destroyed.");
}

void StateMachine::update() {
    states.at(currentState)->update();
}

void StateMachine::render() {
    states.at(currentState)->render();
}

void StateMachine::updateStack() {
    stacked_states.top()->update();
}

void StateMachine::renderStack() {
    stacked_states.top()->render();
}

void StateMachine::change(std::string stateName) {
    try {
        states.at(stateName);
        currentState = stateName;
        print("state swapped to " + stateName);
    } catch (std::out_of_range) {
        print("no state of that name loaded in the state machine");
    }
    // print("no function definition set up");
}

void StateMachine::add(string name, State* state) {
    print("added " + name + " to array of states");
    states[name] = state;
}

void StateMachine::push(State* state) {
    stacked_states.push(state);
    state->onEnter();
}

void StateMachine::pop() {
    if (!stacked_states.empty()) {
        stacked_states.top()->onExit();
        stacked_states.pop();
        stacked_states.top()->onEnter();
    }
}

void StateMachine::printStates() {
    unordered_map<string, State*>::iterator it = states.begin();
    std::cout << "\nStates Loaded:" << std::endl;
    while (it != states.end()) {
        std::cout << it->first << std::endl;
        ++it;
    }
    std::cout << "\n";
}