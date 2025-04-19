#include "Fox.h"

const int FOX_STRENGTH = 3;
const int FOX_INITIATIVE = 7;
const char FOX_SYMBOL = 'F';

#pragma region Private methods
bool Fox::encounteredStrongerOrganism() {
	Organism* other = world->getCollidingOrganism(this);
	if (other == nullptr) {
		return false;
	}
	return other->getStrength() > this->getStrength();
}
#pragma endregion

#pragma region Protected methods
std::string Fox::getName() const {
	return "Fox";
}
#pragma endregion

#pragma region Public methods
Fox::Fox(int x, int y, World* world)
	: Animal(FOX_STRENGTH, FOX_INITIATIVE, FOX_SYMBOL, x, y, world) {}

void Fox::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(1);
		setPosition(randomNeighbor);
	} while (position == getPosition() || encounteredStrongerOrganism());
}
#pragma endregion