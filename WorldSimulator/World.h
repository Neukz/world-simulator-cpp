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
	void drawHorizontalBorder() const;

public:
	World(int width, int height);

	void makeTurn();
	void drawWorld();
	void addOrganism(Organism* organism);
	void removeOrganism(Organism* organism);

	int getWidth() const;
	int getHeight() const;

	~World();
};