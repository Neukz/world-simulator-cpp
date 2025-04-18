#include "World.h"
#include <iostream>

#pragma region Private methods
void World::eraseWorld() const {
	system("cls");	// Clear the screen
}

void World::drawHorizontalBorder() const {
	std::cout << ' ';
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
	std::cout << ' ' << std::endl;
}
#pragma endregion

#pragma region Public methods
World::World(int width, int height)
	: width(width), height(height) {}

void World::makeTurn() {
	for (Organism* organism : organisms) {
		organism->action();
	}
}

void World::drawWorld() {
	eraseWorld();
	std::cout << "Author: Kacper Neumann, 203394" << std::endl;
	drawHorizontalBorder();

	// Sort organisms by position an draw them
	organisms.sort(Organism::compareByPosition);
	auto organism = organisms.begin();
	for (int y = 0; y < height; y++) {
		std::cout << '|';
		for (int x = 0; x < width; x++) {
			if (organism != organisms.end() && (*organism)->getPosition() == Position(x, y)) {
				(*organism)->draw();
				organism++;
			} else {
				std::cout << ' ';
			}
		}
		std::cout << '|' << std::endl;
	}

	drawHorizontalBorder();
}

int World::getWidth() const {
	return width;
}

int World::getHeight() const {
	return height;
}

void World::addOrganism(Organism* organism) {
	organisms.push_back(organism);
}

void World::removeOrganism(Organism* organism) {
	organisms.remove(organism);
	delete organism;
}

World::~World() {
	for (Organism* organism : organisms) {
		delete organism;
	}
}
#pragma endregion