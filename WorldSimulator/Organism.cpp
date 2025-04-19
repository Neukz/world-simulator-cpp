#include "Organism.h"

#pragma region Public methods
Organism::Organism(int strength, int initiative, char symbol, int x, int y, World* world)
	: strength(strength), initiative(initiative), symbol(symbol), position(x, y), prevPosition(x, y), world(world) {
	world->addOrganism(this);
}

bool Organism::compareByPosition(Organism* organism1, Organism* organism2) {
	return organism1->getPosition() < organism2->getPosition();
}

bool Organism::compareByInitiativeAndAge(Organism* organism1, Organism* organism2) {
	int initiative1 = organism1->getInitiative();
	int initiative2 = organism2->getInitiative();
	if (initiative1 == initiative2) {
		return organism1->getAge() > organism2->getAge();	// If initiative is the same, older is higher priority
	}
	return initiative1 > initiative2;	// Higher initiative is higher priority
}

void Organism::draw() const {
	std::cout << symbol;
}

std::string Organism::identify() const {
	return getName();
}

void Organism::mature() {
	age++;
}

void Organism::kill() {
	alive = false;
}

int Organism::getAge() const {
	return age;
}

bool Organism::isAlive() const {
	return alive;
}

void Organism::setPosition(int x, int y) {
	if (x < 0 || y < 0 || x >= world->getWidth() || y >= world->getHeight()) {	// Position out of bounds
		return;
	}
	position.setX(x);
	position.setY(y);
}

void Organism::setPrevPosition(int x, int y) {
	prevPosition.setX(x);
	prevPosition.setY(y);
}

int Organism::getStrength() const {
	return strength;
}

int Organism::getInitiative() const {
	return initiative;
}

Position Organism::getPosition() const {
	return position;
}

Position Organism::getPrevPosition() const {
	return prevPosition;
}
#pragma endregion