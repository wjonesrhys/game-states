#pragma once
#include <SFML/Graphics.hpp>
#include <game.hpp>

#include <iostream>
#include <vector>

class MainMenuState : public State {
    private:
        Game* game;
    public:
        MainMenuState(Game* game) {
            this->game = game;
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