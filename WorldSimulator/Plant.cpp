#include "Plant.h"

#pragma region Private methods
void Plant::sow() {
	bool canReproduce = (rand() % 100) < SowingProbability;
	if (canReproduce) {
		reproduce();
	}
}
#pragma endregion

#pragma region Public methods
Plant::Plant(int strength, char symbol, int x, int y, World* world)
	: Organism(strength, 0, symbol, x, y, world) {}

void Plant::action() {
	sow();
}

void Plant::collision(Organism* other) {
	this->kill(other);
}
#pragma endregion