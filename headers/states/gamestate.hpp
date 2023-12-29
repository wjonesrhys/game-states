#pragma once
#include <iostream>
#include <state.hpp>

class GameState : public State {
    private:

    public:
        GameState();
        ~GameState();

        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;
};