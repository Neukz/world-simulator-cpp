#include "Animal.h"
#include <iostream>

#pragma region Public methods
Animal::Animal(int strength, int initiative, char symbol, int x, int y, World* world)
	: Organism(strength, initiative, symbol, x, y, world) {}

void Animal::action() {
	Position position = getPosition();
	do {
		int dx = rand() % 3 - 1;
		int dy = rand() % 3 - 1;
		setPosition(position.getX() + dx, position.getY() + dy);
	} while (position == getPosition());
}

void Animal::collision(Organism* other) {
	throw std::logic_error("Animal::collision not implemented");
}
#pragma endregion