#include "Sheep.h"
#include "OrganismFactory.h"

const std::string Sheep::Symbol = u8"🐑";
const std::string Sheep::Species = "Sheep";

bool Sheep::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Sheep(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Sheep::getSpecies() const {
	return Species;
}
#pragma endregion

#pragma region Public methods
Sheep::Sheep(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion