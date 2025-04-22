#include "Antelope.h"

#pragma region Private methods
std::string Antelope::toString() const {
	return "Antelope";
}

Organism* Antelope::createNewInstance(int x, int y) {
	return new Antelope(x, y, world);
}

void Antelope::escape() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(1);
		setPosition(randomNeighbor);
	} while (position == getPosition() || world->getCollidingOrganism(this) != nullptr);
	setPrevPosition(position);
}
#pragma endregion

#pragma region Public methods
Antelope::Antelope(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

void Antelope::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(2);
		setPosition(randomNeighbor);
	} while (position == getPosition());
	setPrevPosition(position);
}

void Antelope::collision(Organism* other) {
	bool shouldEscape = (rand() % 100) < 50;	// 50% chance to escape from fight
	if (shouldEscape) {
		return escape();
	}
	Animal::collision(other);
}
#pragma endregion