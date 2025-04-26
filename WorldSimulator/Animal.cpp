#include "Animal.h"

#pragma region Private methods
void Animal::breed(Organism* other) {
	// Revert other's move and reproduce
	Position otherPrevPosition = other->getPrevPosition();
	other->setPosition(otherPrevPosition);
	reproduce();
}
#pragma endregion

#pragma region Public methods
Animal::Animal(int strength, int initiative, std::string symbol, int x, int y, World* world)
	: Organism(strength, initiative, symbol, x, y, world) {}

void Animal::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor();
		setPosition(randomNeighbor);
	} while (position == getPosition());	// Repeat until a valid new position is set
	setPrevPosition(position);
}

void Animal::collision(Organism* other) {
	// If there's an organism of the same type, breed
	if (typeid(*this) == typeid(*other)) {
		return breed(other);
	}

	// Fight
	if (this->getStrength() > other->getStrength()) {
		other->kill(this);
	} else {
		this->kill(other);
	}
}
#pragma endregion