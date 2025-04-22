#include "SowThistle.h"

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
	: Plant(Strength, Symbol, x, y, world) {}

void SowThistle::action() {
	for (int i = 0; i < 3; i++) {
		Plant::action();
	}
}
#pragma endregion