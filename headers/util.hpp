#pragma once
#include "SFML/Graphics.hpp"

void print(std::string msg);
void print(int number);
void print(float number);
void print(double number);

void printCoords(sf::Vector2f coords);
void printCoords(sf::Vector2i coords);
void printCoords(sf::Vector2u coords);
        
float randFloatBetween(int lower, int higher);
int zeroOrOne();