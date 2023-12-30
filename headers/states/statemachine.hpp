#pragma once
#include <iostream>
#include <map>
#include <util.hpp>

using std::string;
using std::map;

class StateMachine {
    private:
        map<string, string> states;    
        // Map<String, IState> mStates = new Map<String, IState>();
        // State* initialState;
        
    public:
        StateMachine();
        ~StateMachine();

        void update();
        void render();
        void change();
        void add(string key, string value);

        void printStates();
};
