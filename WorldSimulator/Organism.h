#pragma once
#include "Position.h"
#include "World.h"

class World;

class Organism {
private:
	int strength;
	int initiative;
	char symbol;
	Position position;
	World* world;
	
public:
	Organism(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() = 0;
	virtual void collision(Organism* other) = 0;

	static bool compareByPosition(Organism* organism1, Organism* organism2);

	void draw() const;

	void setPosition(int x, int y);

	int getStrength() const;
	int getInitiative() const;
	Position getPosition() const;
};