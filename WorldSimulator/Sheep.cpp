#include "Sheep.h"
#include "OrganismFactory.h"

const std::string Sheep::Symbol = u8"🐑";

bool Sheep::registered = [] {
	OrganismFactory::getInstance().registerType("Sheep",
		[](int x, int y, World* world) {
		return new Sheep(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Sheep::toString() const {
	return "Sheep";
}
#pragma endregion

#pragma region Public methods
Sheep::Sheep(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}
#pragma endregion