#include "Organism.h"

#pragma region Protected methods
Organism* Organism::reproduce(Organism* other) {
	// Go back to previous position
	Position otherPrevPosition = other->getPrevPosition();
	other->setPosition(otherPrevPosition);

	Position position = getPosition();
	Position childPosition = world->getRandomFreeNeighboringField(this);
	if (childPosition == Position::InvalidPosition) {
		return nullptr;	// No space to reproduce
	}
	int childX = childPosition.getX();
	int childY = childPosition.getY();
	return createNewInstance(childX, childY);
}
#pragma endregion

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
	return toString();
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

void Organism::setPosition(const Position& newPosition) {
	if (world->positionWithinBounds(newPosition)) {
		int x = newPosition.getX();
		int y = newPosition.getY();
		position.setX(x);
		position.setY(y);
	}
}

void Organism::setPrevPosition(const Position& newPosition) {
	prevPosition.setX(newPosition.getX());
	prevPosition.setY(newPosition.getY());
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