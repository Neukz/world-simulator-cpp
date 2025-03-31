#include "World.h"

World::World(int width, int height)
	: width(width), height(height) {}

void World::eraseWorld() const {
	std::cout << "\033[2J\033[H";	// Clear the screen
}

void World::drawHorizontalBorder() const {
	std::cout << ' ';
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
	std::cout << ' ' << std::endl;
}

void World::makeTurn() {
	throw std::logic_error("World::makeTurn not implemented");
}

void World::drawWorld() {
	eraseWorld();
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