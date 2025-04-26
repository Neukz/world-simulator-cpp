#include "SowThistle.h"
#include "OrganismFactory.h"

const std::string SowThistle::Symbol = u8"🌱";

bool SowThistle::registered = [] {
	OrganismFactory::getInstance().registerType("Sow Thistle",
		[](int x, int y, World* world) {
		return new SowThistle(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string SowThistle::toString() const {
	return "Sow Thistle";
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