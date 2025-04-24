#include "Grass.h"
#include "OrganismFactory.h"

bool Grass::registered = [] {
	OrganismFactory::getInstance().registerType("Grass",
		[](int x, int y, World* world) {
		return new Grass(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Grass::toString() const {
	return "Grass";
}
#pragma endregion

#pragma region Public methods
Grass::Grass(int x, int y, World* world)
	: Plant(Strength, Symbol, x, y, world) {}
#pragma endregion