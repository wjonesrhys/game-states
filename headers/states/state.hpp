#pragma once
#include <iostream>
#include <util.hpp>

/**
 * A Virtual class used for contract purposes amongst the game states.
*/
class State {
    public:
        State() {};
        virtual ~State() {};

        virtual void onEnter();
        virtual void onExit();
        virtual void update();
        virtual void render();
};