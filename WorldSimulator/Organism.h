#pragma once
#include "Position.h"
#include "World.h"

class World;

class Organism {
private:
	int age = 0;
	bool alive = true;
	int strength;
	int initiative;
	char symbol;
	Position position;

protected:
	World* world;
	
public:
	Organism(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() = 0;
	virtual Organism* collision(Organism* other) = 0;

	static bool compareByPosition(Organism* organism1, Organism* organism2);
	static bool compareByInitiativeAndAge(Organism* organism1, Organism* organism2);

	void draw() const;

	void mature();
	void kill();
	void setPosition(int x, int y);

	int getAge() const;
	bool isAlive() const;
	int getStrength() const;
	int getInitiative() const;
	Position getPosition() const;
};