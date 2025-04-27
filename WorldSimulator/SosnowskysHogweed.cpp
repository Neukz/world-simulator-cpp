#include "SosnowskysHogweed.h"
#include "Animal.h"
#include "OrganismFactory.h"

const std::string SosnowskysHogweed::Symbol = u8"🍄";
const std::string SosnowskysHogweed::Species = "Sosnowsky's Hogweed";

bool SosnowskysHogweed::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new SosnowskysHogweed(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string SosnowskysHogweed::getSpecies() const {
	return Species;
}

void SosnowskysHogweed::killNeighboringAnimals() {
	Position position = getPosition();
	std::vector<Position> neighbors = position.getNeighbors();
	for (Position neighbor : neighbors) {
		Organism* organism = world->getOrganismAt(neighbor);
		if (dynamic_cast<Animal*>(organism)) {
			organism->kill(this);
		}
	}
}
#pragma endregion

#pragma region Public methods
SosnowskysHogweed::SosnowskysHogweed(int x, int y, World* world)
	: Plant(Strength, Symbol, x, y, world) {}

void SosnowskysHogweed::action() {
	killNeighboringAnimals();
	Plant::action();
}

void SosnowskysHogweed::collision(Organism* other) {
	Plant::collision(other);
	other->kill(this);
}
#pragma endregion