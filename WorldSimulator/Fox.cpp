#include "Fox.h"

const int FOX_STRENGTH = 3;
const int FOX_INITIATIVE = 7;
const char FOX_SYMBOL = 'F';

#pragma region Private methods
std::string Fox::toString() const {
	return "Fox";
}

Organism* Fox::createNewInstance(int x, int y) {
	return new Fox(x, y, world);
}

bool Fox::encounteredStrongerOrganism() {
	Organism* other = world->getCollidingOrganism(this);
	if (other == nullptr) {
		return false;
	}
	return other->getStrength() > this->getStrength();
}
#pragma endregion

#pragma region Public methods
Fox::Fox(int x, int y, World* world)
	: Animal(FOX_STRENGTH, FOX_INITIATIVE, FOX_SYMBOL, x, y, world) {}

void Fox::action() {
	Position position = getPosition();
	std::vector<Position> neighbors = position.getNeighbors();
	while (!neighbors.empty()) {
		int i = rand() % neighbors.size();
		Position randomNeighbor = neighbors[i];
		setPosition(randomNeighbor);
		neighbors.erase(neighbors.begin() + i);
		if (position != getPosition() && !encounteredStrongerOrganism()) {
			setPrevPosition(position);
			break;
		}
	}
}
#pragma endregion