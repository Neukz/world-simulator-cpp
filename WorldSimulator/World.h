#pragma once
#include <list>
#include <queue>
#include "Organism.h"

class Organism;

class World {
private:
	int width;
	int height;
	std::list<Organism*> organisms;
	std::queue<std::string> events;

	void eraseWorld() const;
	void printTopBorder() const;
	void printBottomBorder() const;
	void printAuthor() const;
	void removeOrganism(Organism* organism);
	void reportKill(Organism* winner, Organism* loser);
	void reportSpawn(Organism* organism);
	void announceEvents();

public:
	World(int width, int height);

	void makeTurn();
	void drawWorld();
	void addOrganism(Organism* organism);
	bool positionWithinBounds(const Position& position) const;
	Organism* getOrganismAt(const Position& position) const;
	Organism* getCollidingOrganism(Organism* organism) const;
	Position getRandomFreeNeighboringField(Organism* organism) const;

	int getWidth() const;
	int getHeight() const;

	~World();
};