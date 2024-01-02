#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <state.hpp>
#include <menu.hpp>
#include <statemachine.hpp>

class ExampleState2 : public State {
    private:
        StateMachine& stateMachine;
        sf::RenderWindow& window;
        Menu menu;
        // static int count;

    public:
        ExampleState2(sf::RenderWindow& renderWindow, StateMachine& stateMachine);
        ~ExampleState2();
        
        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;
        // static int getCounter();
};