#pragma once
#include <list>
#include "Organism.h"

class Organism;

class World {
private:
	int width;
	int height;
	std::list<Organism*> organisms;

	void eraseWorld() const;
	void printTopBorder() const;
	void printBottomBorder() const;
	void printAuthor() const;
	void removeOrganism(Organism* organism);

public:
	World(int width, int height);

	void makeTurn();
	void drawWorld();
	void addOrganism(Organism* organism);

	int getWidth() const;
	int getHeight() const;
	Organism* getCollidingOrganism(Organism* organism) const;

	~World();
};