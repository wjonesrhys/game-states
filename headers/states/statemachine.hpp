#pragma once
#include <iostream>
#include <state.hpp>
#include <emptystate.hpp>
#include <util.hpp>

class StateMachine {
    private:
        // Map<String, IState> mStates = new Map<String, IState>();
        // State* initialState;
        
    public:
        StateMachine();
        ~StateMachine();

        void update();
        void render();
        void change();
        void add();

};
