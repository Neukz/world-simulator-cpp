#include "Wolf.h"

#pragma region Private methods
std::string Wolf::toString() const {
	return "Wolf";
}

Organism* Wolf::createNewInstance(int x, int y) {
	return new Wolf(x, y, world);
}
#pragma endregion

#pragma region Public methods
Wolf::Wolf(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion