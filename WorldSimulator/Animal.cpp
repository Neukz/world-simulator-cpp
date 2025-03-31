#include "Animal.h"
#include <iostream>

Animal::Animal(int strength, int initiative, char symbol, int x, int y, World* world)
	: Organism(strength, initiative, symbol, x, y, world) {}

void Animal::action() {
	throw std::logic_error("Animal::action not implemented");
}

void Animal::collision(Organism* other) {
	throw std::logic_error("Animal::collision not implemented");
}