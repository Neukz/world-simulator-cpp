#include "World.h"

#pragma region Private methods
void World::eraseWorld() const {
	system("cls");	// Clear the screen
}

void World::printTopBorder() const {
	std::cout << u8"╔";
	for (int i = 0; i < width; i++) {
		std::cout << u8"═";
	}
	std::cout << u8"╗" << std::endl;
}

void World::printBottomBorder() const {
	std::cout << u8"╚";
	for (int i = 0; i < width; i++) {
		std::cout << u8"═";
	}
	std::cout << u8"╝" << std::endl;
}

void World::printAuthor() const {
	std::cout << "Author: Kacper Neumann, 203394" << std::endl;
}

void World::removeOrganism(Organism* organism) {
	organisms.remove(organism);
	delete organism;
}

void World::reportKill(Organism* winner, Organism* loser) const {
	std::cout
		<< loser->identify()
		<< " has been killed by "
		<< winner->identify()
		<< " at "
		<< loser->getPosition()
		<< "."
		<< std::endl;
}
#pragma endregion

#pragma region Public methods
World::World(int width, int height)
	: width(width), height(height) {
	std::setlocale(LC_ALL, "en_US.UTF-8");	// Support unicode characters
	srand(time(nullptr));
}

Organism* World::getCollidingOrganism(Organism* organism) const {
	auto other = std::find_if(
		organisms.begin(), organisms.end(),
		[organism](Organism* other) {
		return other != organism && other->getPosition() == organism->getPosition();
	});
	return other == organisms.end() ? nullptr : *other;
}

void World::makeTurn() {
	// Sort organisms by initiative and age, then call action() for each
	organisms.sort(Organism::compareByInitiativeAndAge);
	std::list<Organism*> toRemove;
	for (Organism* organism : organisms) {
		if (organism->isAlive()) {
			organism->mature();
			organism->action();
			// Check for collision
			Organism* other = getCollidingOrganism(organism);
			if (other != nullptr) {
				Organism* loser = other->collision(organism);
				if (loser != nullptr) {
					Organism* winner = organism == loser ? other : organism;
					toRemove.push_back(loser);
					reportKill(winner, loser);
				}
			}
		}
	}

	// Remove organisms that lost their fights
	for (Organism* organism : toRemove) {
		removeOrganism(organism);
	}
}

void World::drawWorld() {
	//eraseWorld();
	//printAuthor();
	printTopBorder();

	// Sort organisms by position an draw them
	organisms.sort(Organism::compareByPosition);
	auto organism = organisms.begin();
	for (int y = 0; y < height; y++) {
		std::cout << u8"║";
		for (int x = 0; x < width; x++) {
			if (organism != organisms.end() && (*organism)->getPosition() == Position(x, y)) {
				(*organism)->draw();
				organism++;
			} else {
				std::cout << ' ';	// Unoccupied cell
			}
		}
		std::cout << u8"║" << std::endl;
	}

	printBottomBorder();
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

World::~World() {
	for (Organism* organism : organisms) {
		delete organism;
	}
}
#pragma endregion