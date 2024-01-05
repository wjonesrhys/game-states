#pragma once
#include <iostream>
#include <util.hpp>
#include <state.hpp>

#include <stack>

using std::string;
using std::unordered_map;
using std::stack;

class StateMachine {
    private:
        unordered_map<string, State*> states;    
        stack<State*> stacked_states;
        string currentState;
        
    public:
        StateMachine();
        ~StateMachine();

        void update();
        void render();

        void updateStack();
        void renderStack();

        /* Normal */
        void change(string stateName);
        void add(string name, State* state);

        /* Stack */
        void push(State* state);
        void pop();

        void printStates();
};
