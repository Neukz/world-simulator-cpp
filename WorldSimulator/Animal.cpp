#include "Animal.h"
#include <iostream>

#pragma region Public methods
Animal::Animal(int strength, int initiative, char symbol, int x, int y, World* world)
	: Organism(strength, initiative, symbol, x, y, world) {}

void Animal::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(1);
		setPosition(randomNeighbor.getX(), randomNeighbor.getY());
	} while (position == getPosition());
	setPrevPosition(position.getX(), position.getY());
}

Organism* Animal::collision(Organism* other) {
	//if (typeid(*this) == typeid(*other)) {
		//breed();
		//return nullptr;
	//}
	// Return the organism to be removed
	if (this->getStrength() > other->getStrength()) {
		other->kill();
		return other;
	} else {
		this->kill();
		return this;
	}
}

void Animal::breed() const {
	throw std::logic_error("Animal::breed not implemented");
}
#pragma endregion