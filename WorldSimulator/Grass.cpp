#include "Grass.h"
#include "OrganismFactory.h"

const std::string Grass::Symbol = u8"🌿";
const std::string Grass::Species = "Grass";

bool Grass::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Grass(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Grass::getSpecies() const {
	return Species;
}
#pragma endregion

#pragma region Public methods
Grass::Grass(int x, int y, World* world)
	: Plant(Strength, Symbol, x, y, world) {}
#pragma endregion