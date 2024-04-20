#pragma once
#include <iostream>
#include <util.hpp>
#include <state.hpp>

#include <stack>
#include <unordered_map>

class StateMachine {
    private:
        std::unordered_map<std::string, State*> states;    
        std::stack<State*> stacked_states;
        std::string currentState;
        
    public:
        StateMachine();
        ~StateMachine();

        void update();
        void render();

        void updateStack();
        void renderStack();

        /* Normal */
        void change(std::string stateName);
        void add(std::string name, State* state);

        /* Stack */
        void push(State* state);
        void pop();

        void printStates();
};
