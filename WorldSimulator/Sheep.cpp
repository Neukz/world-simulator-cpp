#include "Sheep.h"

const int SHEEP_STRENGTH = 4;
const int SHEEP_INITIATIVE = 4;
const char SHEEP_SYMBOL = 'S';

#pragma region Private methods
std::string Sheep::toString() const {
	return "Sheep";
}

Organism* Sheep::createNewInstance(int x, int y) {
	return new Sheep(x, y, world);
}
#pragma endregion

#pragma region Public methods
Sheep::Sheep(int x, int y, World* world)
	: Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, SHEEP_SYMBOL, x, y, world) {}
#pragma endregion