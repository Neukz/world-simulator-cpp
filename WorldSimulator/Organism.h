#pragma once
#include <iostream>
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
	Position prevPosition;

protected:
	World* world;

	virtual std::string getName() const = 0;
	
public:
	Organism(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() = 0;
	virtual Organism* collision(Organism* other) = 0;

	static bool compareByPosition(Organism* organism1, Organism* organism2);
	static bool compareByInitiativeAndAge(Organism* organism1, Organism* organism2);

	void draw() const;
	std::string identify() const;

	void mature();
	void kill();
	void setPosition(const Position& newPosition);
	void setPrevPosition(const Position& newPosition);

	int getAge() const;
	bool isAlive() const;
	int getStrength() const;
	int getInitiative() const;
	Position getPosition() const;
	Position getPrevPosition() const;
};