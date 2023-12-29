#pragma once
#include <iostream>
#include <util.hpp>

/**
 * A Virtual class used for contract purposes amongst the game states.
*/
class State {
    public:
        State() {};
        ~State() {};

        virtual void onEnter();
        virtual void onExit();
        virtual void update();
        virtual void render();
        void setStateName(const std::string& name);

    protected:
        std::string stateName;
};