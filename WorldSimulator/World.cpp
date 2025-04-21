#include "World.h"
#include <sstream>
#include <vector>
#include "Animal.h"
#include "Plant.h"

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

void World::reportDeath(Organism* winner, Organism* loser) {
	// If the loser was a Plant, that means it was eaten
	std::string reason = dynamic_cast<Plant*>(loser) ? "eaten" : "killed";

	std::ostringstream info;
	info
		<< "\033[31m"
		<< loser->identify()
		<< " has been "
		<< reason
		<< " by "
		<< winner->identify()
		<< " at "
		<< loser->getPosition()
		<< ".\033[0m";

	events.push(info.str());
}

void World::reportSpawn(Organism* organism) {
	std::ostringstream info;
	info
		<< "\033[32m"
		<< organism->identify()
		<< " has been spawned at "
		<< organism->getPosition()
		<< ".\033[0m";

	events.push(info.str());
}

void World::announceEvents() {
	while (!events.empty()) {
		std::cout << events.front() << std::endl;
		events.pop();
	}
}
#pragma endregion

#pragma region Public methods
World::World(int width, int height)
	: width(width), height(height) {
	std::setlocale(LC_ALL, "en_US.UTF-8");	// Support unicode characters
	srand(time(nullptr));
}

void World::makeTurn() {
	// Sort organisms by initiative and age
	organisms.sort(Organism::compareByInitiativeAndAge);
	std::list<Organism*> toRemove;
	int populationInTurn = organisms.size(), populationCount = 0;
	for (Organism* organism : organisms) {
		// Prevent new organisms from calling action() in the same turn they were spawned
		if (populationCount++ >= populationInTurn) {
			break;
		}

		// Skip dead organisms
		if (!organism->isAlive()) {
			continue;
		}

		organism->mature();
		organism->action();

		// If it's an Animal, check for collision
		if (dynamic_cast<Animal*>(organism)) {
			Organism* other = getCollidingOrganism(organism);
			if (other == nullptr) {
				continue;
			}

			Organism* resultOrganism = other->collision(organism);
			if (resultOrganism == nullptr) {	// Both survived
				continue;
			}

			if (resultOrganism->isAlive()) {	// New organism was spawned
				reportSpawn(resultOrganism);
			} else {
				Organism* winner = organism == resultOrganism ? other : organism;
				toRemove.push_back(resultOrganism);
				reportDeath(winner, resultOrganism);
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
	announceEvents();
}

void World::populate(std::initializer_list<Organism*> organisms) {
	for (Organism* organism : organisms) {
		addOrganism(organism);
	}
}

void World::addOrganism(Organism* organism) {
	organisms.push_back(organism);
	reportSpawn(organism);
}

bool World::positionWithinBounds(const Position& position) const {
	int x = position.getX();
	int y = position.getY();
	return x >= 0 && y >= 0 && x < width && y < height;
}

Organism* World::getOrganismAt(const Position& position) const {
	auto organism = std::find_if(
		organisms.begin(), organisms.end(),
		[position](Organism* organism) {
		return organism->isAlive() && organism->getPosition() == position;
	});
	return organism == organisms.end() ? nullptr : *organism;
}

Organism* World::getCollidingOrganism(Organism* organism) const {
	auto other = std::find_if(
		organisms.begin(), organisms.end(),
		[organism](Organism* other) {
		return other->isAlive() && other != organism && other->getPosition() == organism->getPosition();
	});
	return other == organisms.end() ? nullptr : *other;
}

Position World::getRandomFreeNeighboringField(Organism* organism) const {
	Position position = organism->getPosition();
	int x = position.getX();
	int y = position.getY();
	std::vector<Position> neighbors = {
		Position(x, y - 1),
		Position(x, y + 1),
		Position(x - 1, y),
		Position(x + 1, y)
	};
	while (!neighbors.empty()) {
		int i = rand() % neighbors.size();
		Position randomNeighbor = neighbors[i];
		if (positionWithinBounds(randomNeighbor) && getOrganismAt(randomNeighbor) == nullptr) {
			return randomNeighbor;
		}
		neighbors.erase(neighbors.begin() + i);
	}
	return Position::InvalidPosition;	// All neighboring fields are occupied
}

int World::getWidth() const {
	return width;
}

int World::getHeight() const {
	return height;
}

World::~World() {
	for (Organism* organism : organisms) {
		delete organism;
	}
}
#pragma endregion