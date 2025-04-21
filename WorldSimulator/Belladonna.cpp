#include "Belladonna.h"

const int BELLADONNA_STRENGTH = 99;
const char BELLADONNA_SYMBOL = 'b';

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
	: Plant(BELLADONNA_STRENGTH, BELLADONNA_SYMBOL, x, y, world) {}

void Belladonna::collision(Organism* other) {
	Plant::collision(other);
	other->kill(this);
}
#pragma endregion