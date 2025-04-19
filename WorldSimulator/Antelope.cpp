#include "Antelope.h"

const int ANTELOPE_STRENGTH = 4;
const int ANTELOPE_INITIATIVE = 4;
const char ANTELOPE_SYMBOL = 'A';

#pragma region Private methods
void Antelope::escape() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(1);
		setPosition(randomNeighbor.getX(), randomNeighbor.getY());
	} while (position == getPosition() || world->getCollidingOrganism(this) != nullptr);
	setPrevPosition(position.getX(), position.getY());
}
#pragma endregion

#pragma region Protected methods
std::string Antelope::getName() const {
	return "Antelope";
}
#pragma endregion

#pragma region Public methods
Antelope::Antelope(int x, int y, World* world)
	: Animal(ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, ANTELOPE_SYMBOL, x, y, world) {}

void Antelope::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(2);
		setPosition(randomNeighbor.getX(), randomNeighbor.getY());
	} while (position == getPosition());
	setPrevPosition(position.getX(), position.getY());
}

Organism* Antelope::collision(Organism* other) {
	bool shouldEscape = (rand() % 100) < 50;	// 50% chance to escape from fight
	if (shouldEscape) {
		escape();
		return nullptr;
	}
	Animal::collision(other);
}
#pragma endregion