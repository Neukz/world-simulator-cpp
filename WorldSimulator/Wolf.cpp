#include "Wolf.h"
#include "OrganismFactory.h"

const std::string Wolf::Symbol = u8"🐺";
const std::string Wolf::Species = "Wolf";

bool Wolf::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Wolf(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Wolf::getSpecies() const {
	return Species;
}
#pragma endregion

#pragma region Public methods
Wolf::Wolf(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion