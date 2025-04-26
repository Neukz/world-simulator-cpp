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
	std::string symbol;
	Position position;
	Position prevPosition;

	virtual std::string toString() const = 0;

protected:
	World* world;

	void reproduce();
	
public:
	Organism(int strength, int initiative, std::string symbol, int x, int y, World* world);

	static bool compareByPosition(Organism* organism1, Organism* organism2);
	static bool compareByInitiativeAndAge(Organism* organism1, Organism* organism2);

	virtual void action() = 0;
	virtual void collision(Organism* other) = 0;
	virtual std::string serialize() const;

	void draw() const;
	std::string identify() const;

	void mature();
	void kill(Organism* killer);
	void setAge(int age);
	void setStrength(int strength);
	void setPosition(const Position& newPosition);
	void setPrevPosition(const Position& newPosition);

	int getAge() const;
	bool isAlive() const;
	int getStrength() const;
	int getInitiative() const;
	Position getPosition() const;
	Position getPrevPosition() const;
};