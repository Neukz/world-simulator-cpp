#include "SosnowskysHogweed.h"
#include "Animal.h"
#include "OrganismFactory.h"

bool SosnowskysHogweed::registered = [] {
	OrganismFactory::getInstance().registerType("Sosnowsky's Hogweed",
		[](int x, int y, World* world) {
		return new SosnowskysHogweed(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string SosnowskysHogweed::toString() const {
	return "Sosnowsky's Hogweed";
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