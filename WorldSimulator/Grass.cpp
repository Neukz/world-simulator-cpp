#include "Grass.h"

const int GRASS_STRENGTH = 0;
const char GRASS_SYMBOL = 'g';

#pragma region Private methods
std::string Grass::toString() const {
	return "Grass";
}

Organism* Grass::createNewInstance(int x, int y) {
	return new Grass(x, y, world);
}
#pragma endregion

#pragma region Public methods
Grass::Grass(int x, int y, World* world)
	: Plant(GRASS_STRENGTH, GRASS_SYMBOL, x, y, world) {}
#pragma endregion