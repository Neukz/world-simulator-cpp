#include "Animal.h"

#pragma region Private methods
void Animal::breed(Organism* other) {
	// Go back to previous position
	Position otherPrevPosition = other->getPrevPosition();
	other->setPosition(otherPrevPosition);
	reproduce();
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

void Animal::collision(Organism* other) {
	if (typeid(*this) == typeid(*other)) {
		return breed(other);
	}

	if (this->getStrength() > other->getStrength()) {
		other->kill(this);
	} else {
		this->kill(other);
	}
}
#pragma endregion