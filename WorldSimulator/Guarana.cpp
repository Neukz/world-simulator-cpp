#include "Guarana.h"
#include "OrganismFactory.h"

const std::string Guarana::Symbol = u8"🍒";
const std::string Guarana::Species = "Guarana";

bool Guarana::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Guarana(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Guarana::getSpecies() const {
	return Species;
}

void Guarana::boostEater(Organism* eater) {
	int strength = eater->getStrength();
	eater->setStrength(strength + 3);
}
#pragma endregion

#pragma region Public methods
Guarana::Guarana(int x, int y, World* world)
	: Plant(Strength, Symbol, x, y, world) {}

void Guarana::collision(Organism* other) {
	boostEater(other);
	Plant::collision(other);
}
#pragma endregion