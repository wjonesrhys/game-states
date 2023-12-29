#include "state.hpp"

void State::onEnter() {
    print("no function definition set up");
}

void State::onExit() {
    print("no function definition set up");
}

void State::update() {
    print("no function definition set up");
}

void State::render() {
    print("no function definition set up");
}

void State::setStateName(const std::string& name) {    
    stateName = name;
}