#pragma once
#include <iostream>
#include <state.hpp>

class MainMenuState : public State {
    private:

    public:
        MainMenuState() {
            setStateName("State B");
        }

        void enter() {
            print("i");
            // Additional actions when entering State B
        }

        void onExit() override {
            State::onExit();
            // Additional actions when exiting State B
        }

        void update() override {
            State::update();
            // Additional actions when updating State B
        }
};