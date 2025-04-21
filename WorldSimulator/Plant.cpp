#include "Plant.h"

const int Plant::SowingProbability = 15;

#pragma region Protected methods
Organism* Plant::sow() {
	bool canReproduce = (rand() % 100) < SowingProbability;
	if (canReproduce) {
		return reproduce();
	}
	return nullptr;
}
#pragma endregion

#pragma region Public methods
Plant::Plant(int strength, char symbol, int x, int y, World* world)
	: Organism(strength, 0, symbol, x, y, world) {}

void Plant::action() {
	sow();
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