#include "Plant.h"

#pragma region Public methods
Plant::Plant(int strength, char symbol, int x, int y, World* world)
	: Organism(strength, 0, symbol, x, y, world) {}

void Plant::action() {
	throw std::logic_error("Plant::action not implemented");
}

Organism* Plant::collision(Organism* other) {
	throw std::logic_error("Plant::collision not implemented");
}
#pragma endregion