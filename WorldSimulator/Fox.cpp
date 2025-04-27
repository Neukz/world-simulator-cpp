#include "Fox.h"
#include "OrganismFactory.h"

const std::string Fox::Symbol = u8"🦊";
const std::string Fox::Species = "Fox";

bool Fox::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Fox(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Fox::getSpecies() const {
	return Species;
}

bool Fox::encounteredStrongerOrganism() {
	if (Organism* other = world->getCollidingOrganism(this)) {
		return other->getStrength() > this->getStrength();
	}
	return false;
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
		neighbors.erase(neighbors.begin() + i);

		setPosition(randomNeighbor);
		if (position != getPosition() && !encounteredStrongerOrganism()) {
			setPrevPosition(position);
			break;
		}
	}
}
#pragma endregion