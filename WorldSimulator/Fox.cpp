#include "Fox.h"
#include "OrganismFactory.h"

bool Fox::registered = [] {
	OrganismFactory::getInstance().registerType("Fox",
		[](int x, int y, World* world) {
		return new Fox(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Fox::toString() const {
	return "Fox";
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
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

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