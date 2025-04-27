#include "Organism.h"
#include "OrganismFactory.h"

#pragma region Protected methods
void Organism::reproduce() {
	Position childPosition = world->getRandomFreeNeighboringField(this);
	if (childPosition == Position::InvalidPosition) {
		return;	// No space to reproduce
	}

	std::string type = identify();
	int childX = childPosition.getX();
	int childY = childPosition.getY();
	Organism* child = OrganismFactory::getInstance().create(type, childX, childY, world);
	world->addOrganism(child);
}
#pragma endregion

#pragma region Public methods
Organism::Organism(int strength, int initiative, std::string symbol, int x, int y, World* world)
	: strength(strength), initiative(initiative), symbol(symbol), position(x, y), prevPosition(x, y), world(world) {}

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

int Organism::getAge() const {
	return age;
}

bool Organism::isAlive() const {
	return alive;
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

void Organism::setAge(int age) {
	this->age = age;
}

void Organism::setStrength(int strength) {
	this->strength = strength;
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

void Organism::mature() {
	age++;
}

void Organism::kill(Organism* killer) {
	alive = false;
	world->reportDeath(killer, this);
}

void Organism::draw() const {
	std::cout << symbol;
}


std::string Organism::identify() const {
	return toString();
}

std::string Organism::serialize() const {
	// Convert fields to strings
	std::vector<std::string> fields = {
		toString(),
		std::to_string(age),
		std::to_string(strength),
		std::to_string(position.getX()),
		std::to_string(position.getY()),
		std::to_string(prevPosition.getX()),
		std::to_string(prevPosition.getY()),
	};

	// Join
	std::string serialized = fields[0];
	for (int i = 1; i < fields.size(); i++) {
		serialized += ',' + fields[i];
	}

	return serialized;
}
#pragma endregion