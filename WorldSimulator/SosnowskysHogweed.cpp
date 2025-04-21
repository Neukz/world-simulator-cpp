#include "SosnowskysHogweed.h"
#include "Animal.h"

const int SOSNOWSKYS_HOGWEED_STRENGTH = 10;
const char SOSNOWSKYS_HOGWEED_SYMBOL = 'h';

#pragma region Private methods
std::string SosnowskysHogweed::toString() const {
	return "Sosnowsky's Hogweed";
}

Organism* SosnowskysHogweed::createNewInstance(int x, int y) {
	return new SosnowskysHogweed(x, y, world);
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
	: Plant(SOSNOWSKYS_HOGWEED_STRENGTH, SOSNOWSKYS_HOGWEED_SYMBOL, x, y, world) {}

void SosnowskysHogweed::action() {
	killNeighboringAnimals();
	Plant::action();
}

void SosnowskysHogweed::collision(Organism* other) {
	Plant::collision(other);
	other->kill(this);
}
#pragma endregion