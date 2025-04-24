#include "Guarana.h"
#include "OrganismFactory.h"

bool Guarana::registered = [] {
	OrganismFactory::getInstance().registerType("Guarana",
		[](int x, int y, World* world) {
		return new Guarana(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Guarana::toString() const {
	return "Guarana";
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