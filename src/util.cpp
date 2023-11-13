#include <iostream>

#include <util.hpp>

void print(std::string msg) {
    std::cout << msg << std::endl;
}

void print(int number) {
    std::cout << number << std::endl;
}

void print(float number) {
    std::cout << number << std::endl;
}

void print(double number) {
    std::cout << number << std::endl;
}

void printCoords(sf::Vector2f coords) {
    std::cout << "coords... x: " << coords.x << " y: " << coords.y << std::endl;  
}

void printCoords(sf::Vector2i coords) {
    std::cout << "coords... x: " << coords.x << " y: " << coords.y << std::endl; 
}

void printCoords(sf::Vector2u coords) {
    std::cout << "coords... x: " << coords.x << " y: " << coords.y << std::endl; 
}

float randFloatBetween(int lower, int higher) {
    return 0;
}

int zeroOrOne() {
    int randNum = rand() * 2 / RAND_MAX;

    if (randNum == 0) {
        return -1;
    } 
    return 1;
}

