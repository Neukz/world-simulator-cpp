#include "Sheep.h"

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
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion