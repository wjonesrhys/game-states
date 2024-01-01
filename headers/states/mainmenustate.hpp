#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <state.hpp>
#include <menu.hpp>
#include <statemachine.hpp>

class MainMenuState : public State {
    private:
        StateMachine& stateMachine;
        sf::RenderWindow& window;
        Menu menu;
        // static int count;

    public:
        MainMenuState(sf::RenderWindow& renderWindow, StateMachine& stateMachine);
        ~MainMenuState();
        
        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;
        // static int getCounter();
};