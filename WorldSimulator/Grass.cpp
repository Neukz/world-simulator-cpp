#include "Grass.h"

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
	: Plant(Strength, Symbol, x, y, world) {}
#pragma endregion