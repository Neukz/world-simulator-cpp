#include "Plant.h"

#pragma region Public methods
Plant::Plant(int strength, std::string symbol, int x, int y, World* world)
	: Organism(strength, 0, symbol, x, y, world) {}

void Plant::action() {
	bool canReproduce = (rand() % 100) < SowingProbability;
	if (canReproduce) {
		reproduce();
	}
}

void Plant::collision(Organism* other) {
	this->kill(other);
}
#pragma endregion