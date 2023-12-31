#pragma once
#include <iostream>
#include <unordered_map>
#include <util.hpp>
#include <state.hpp>

using std::string;
using std::unordered_map;

class StateMachine {
    private:
        unordered_map<string, State*> states;    
        string currentState;
        
    public:
        StateMachine();
        ~StateMachine();

        void update();
        void render();
        void change(std::string stateName);
        void add(string name, State* state);

        void printStates();
};
