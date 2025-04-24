#pragma once
#include <list>
#include <queue>
#include <initializer_list>
#include "Organism.h"

class Organism;

class World {
private:
	static const std::string SaveFilename;

	int width;
	int height;
	std::list<Organism*> organisms;
	std::queue<std::string> events;

	void eraseWorld() const;
	void printTopBorder() const;
	void printBottomBorder() const;
	void printAuthor() const;
	void removeDeadOrganisms();
	void reportSpawn(Organism* organism);
	void announceEvents();

public:
	World(int width, int height);

	void makeTurn();
	void drawWorld();
	void populate(std::initializer_list<Organism*> organisms);
	void reportDeath(Organism* winner, Organism* loser);
	void addOrganism(Organism* organism);
	void saveWorld();
	void loadWorld();
	bool positionWithinBounds(const Position& position) const;
	Organism* getOrganismAt(const Position& position) const;
	Organism* getCollidingOrganism(Organism* organism) const;
	Position getRandomFreeNeighboringField(Organism* organism) const;

	int getWidth() const;
	int getHeight() const;

	~World();
};