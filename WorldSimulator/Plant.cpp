#include "Plant.h"

#pragma region Public methods
Plant::Plant(int strength, char symbol, int x, int y, World* world)
	: Organism(strength, 0, symbol, x, y, world) {}

void Plant::action() {
	throw std::logic_error("Plant::action not implemented");
}

Organism* Plant::collision(Organism* other) {
	if (this->getStrength() > other->getStrength()) {
		other->kill();
		return other;
	} else {
		this->kill();
		return this;
	}
}
#pragma endregion