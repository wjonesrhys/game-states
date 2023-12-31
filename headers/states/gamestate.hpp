#pragma once
#include <iostream>
#include <state.hpp>
#include <SFML/Graphics.hpp>
#include <statemachine.hpp>
#include <menu.hpp>

class GameState : public State {
    private:
        StateMachine& stateMachine;
        sf::RenderWindow& window;
        Menu menu;

    public:
        GameState(sf::RenderWindow& renderWindow, StateMachine& stateMachine);
        ~GameState();
        
        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;
};