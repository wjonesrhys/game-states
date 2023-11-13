#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class GameState : public State {
private:

public:
    GameState() {
        setStateName("State B");
    }

    void enter() {
        print("i");
        // Additional actions when entering State B
    }

    void exit() override {
        State::exit();
        // Additional actions when exiting State B
    }

    void update() override {
        State::update();
        // Additional actions when updating State B
    }
};