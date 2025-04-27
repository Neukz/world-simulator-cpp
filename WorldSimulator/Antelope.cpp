#include "Antelope.h"
#include "OrganismFactory.h"

const std::string Antelope::Symbol = u8"🦌";
const std::string Antelope::Species = "Antelope";

bool Antelope::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return new Antelope(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Antelope::getSpecies() const {
	return Species;
}

void Antelope::escape() {
	Position position = getPosition();
	Position randomNeighbor = world->getRandomFreeNeighboringField(this);
	if (randomNeighbor == Position::InvalidPosition) {
		return;	// No space to escape
	}
	
	setPrevPosition(getPosition());
	setPosition(randomNeighbor);
}
#pragma endregion

#pragma region Public methods
Antelope::Antelope(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

void Antelope::action() {
	Position position = getPosition();
	do {
		Position randomNeighbor = position.getRandomNeighbor(2);
		setPosition(randomNeighbor);
	} while (position == getPosition());
	setPrevPosition(position);
}

void Antelope::collision(Organism* other) {
	bool shouldEscape = (rand() % 100) < 50;	// 50% chance to escape from fight
	if (shouldEscape) {
		return escape();
	}
	Animal::collision(other);
}
#pragma endregion