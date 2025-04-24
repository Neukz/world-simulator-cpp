#include "Belladonna.h"
#include "OrganismFactory.h"

bool Belladonna::registered = [] {
	OrganismFactory::getInstance().registerType("Belladonna",
		[](int x, int y, World* world) {
		return new Belladonna(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Belladonna::toString() const {
	return "Belladonna";
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