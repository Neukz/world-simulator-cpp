#include "Guarana.h"

const int GUARANA_STRENGTH = 0;
const char GUARANA_SYMBOL = 'u';

#pragma region Private methods
std::string Guarana::toString() const {
	return "Guarana";
}

Organism* Guarana::createNewInstance(int x, int y) {
	return new Guarana(x, y, world);
}

void Guarana::boostEater(Organism* eater) {
	int strength = eater->getStrength();
	eater->setStrength(strength + 3);
}
#pragma endregion

#pragma region Public methods
Guarana::Guarana(int x, int y, World* world)
	: Plant(GUARANA_STRENGTH, GUARANA_SYMBOL, x, y, world) {}

void Guarana::collision(Organism* other) {
	boostEater(other);
	Plant::collision(other);
}
#pragma endregion