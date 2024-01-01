#pragma once
#include <iostream>
#include <state.hpp>
#include <SFML/Graphics.hpp>
#include <statemachine.hpp>
#include <menu.hpp>

class PlayState : public State {
    private:
        StateMachine& stateMachine;
        sf::RenderWindow& window;
        Menu menu;

    public:
        PlayState(sf::RenderWindow& renderWindow, StateMachine& stateMachine);
        ~PlayState();
        
        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;
};