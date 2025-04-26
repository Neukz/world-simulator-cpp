#include "Wolf.h"
#include "OrganismFactory.h"

const std::string Wolf::Symbol = u8"🐺";

bool Wolf::registered = [] {
	OrganismFactory::getInstance().registerType("Wolf",
		[](int x, int y, World* world) {
		return new Wolf(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Wolf::toString() const {
	return "Wolf";
}
#pragma endregion

#pragma region Public methods
Wolf::Wolf(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion