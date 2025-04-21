#include "SowThistle.h"

const int SOW_THISTLE_STRENGTH = 0;
const char SOW_THISTLE_SYMBOL = 's';

#pragma region Private methods
std::string SowThistle::toString() const {
	return "Sow Thistle";
}

Organism* SowThistle::createNewInstance(int x, int y) {
	return new SowThistle(x, y, world);
}
#pragma endregion

#pragma region Public methods
SowThistle::SowThistle(int x, int y, World* world)
	: Plant(SOW_THISTLE_STRENGTH, SOW_THISTLE_SYMBOL, x, y, world) {}

void SowThistle::action() {
	for (int i = 0; i < 3; i++) {
		Plant::action();
	}
}
#pragma endregion