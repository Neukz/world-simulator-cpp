#include "Animal.h"

#pragma region Private methods
Organism* Animal::breed(Organism* other) {
	// Go back to previous position
	Position otherPrevPosition = other->getPrevPosition();
	other->setPosition(otherPrevPosition);
	return reproduce();
}
#pragma endregion

#pragma region Public methods
Animal::Animal(int strength, int initiative, char symbol, int x, int y, World* world)
	: Organism(strength, initiative, symbol, x, y, world) {}

void Animal::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(1);
		setPosition(randomNeighbor);
	} while (position == getPosition());
	setPrevPosition(position);
}

Organism* Animal::collision(Organism* other) {
	if (typeid(*this) == typeid(*other)) {
		Organism* child = breed(other);
		return child;
	}
	// Return the organism to be removed
	if (this->getStrength() > other->getStrength()) {
		other->kill();
		return other;
	} else {
		this->kill();
		return this;
	}
}
#pragma endregion