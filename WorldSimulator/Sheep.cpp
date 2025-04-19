#include "Sheep.h"

const int SHEEP_STRENGTH = 4;
const int SHEEP_INITIATIVE = 4;
const char SHEEP_SYMBOL = 'S';

#pragma region Protected methods
std::string Sheep::getName() const {
	return "Sheep";
}
#pragma endregion

#pragma region Public methods
Sheep::Sheep(int x, int y, World* world)
	: Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, SHEEP_SYMBOL, x, y, world) {}
#pragma endregion