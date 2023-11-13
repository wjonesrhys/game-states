#pragma once
#include <iostream>
#include <util.hpp>

/**
 * A Virtual class used for contract purposes amongst the game states.
*/
class State {
public:
    // Constructor
    State() {};
    ~State() {};

    // Virtual method to enter the state
    virtual void enter() {
        print("a");
    };
    // Virtual method to exit the state
    virtual void exit() {
        print("a");
    };
    // Virtual method to update the state
    virtual void update() {
        print("a");
    };
    // Setter for the state name
    void setStateName(const std::string& name) {    
        stateName = name;
    };

protected:
    std::string stateName;
};