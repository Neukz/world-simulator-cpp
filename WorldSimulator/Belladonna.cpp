#include "Belladonna.h"
#include "OrganismFactory.h"

const std::string Belladonna::Symbol = u8"🫐";
const std::string Belladonna::Species = "Belladonna";

bool Belladonna::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Belladonna(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Belladonna::getSpecies() const {
	return Species;
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