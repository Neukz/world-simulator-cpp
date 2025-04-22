#include "Belladonna.h"

#pragma region Private methods
std::string Belladonna::toString() const {
	return "Belladonna";
}

Organism* Belladonna::createNewInstance(int x, int y) {
	return new Belladonna(x, y, world);
}
#pragma endregion

#pragma region Public methods
Belladonna::Belladonna(int x, int y, World* world)
	: Plant(Strength, Symbol, x, y, world) {}

void Belladonna::collision(Organism* other) {
	Plant::collision(other);
	other->kill(this);
}
#pragma endregion