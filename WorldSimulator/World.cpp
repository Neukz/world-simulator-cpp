#include "World.h"
#include <Windows.h>
#include <sstream>
#include <fstream>
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
#include "OrganismFactory.h"

const std::string World::SaveFilename = "save.txt";

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

void World::removeDeadOrganisms() {
	organisms.remove_if([](Organism* organism) {
		if (!organism->isAlive()) {
			delete organism;
			return true;
		}
		return false;
	});
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
	SetConsoleOutputCP(CP_UTF8);	// Support unicode characters
	srand(time(nullptr));
}

void World::makeTurn() {
	organisms.sort(Organism::compareByInitiativeAndAge);
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

		if (dynamic_cast<Human*>(organism)) {
			std::cout << "Human's turn..." << std::endl;
		}
		organism->action();

		// If it's an Animal, check for collision
		if (dynamic_cast<Animal*>(organism)) {
			if (Organism* other = getCollidingOrganism(organism)) {
				other->collision(organism);
			}
		}
	}

	removeDeadOrganisms();
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

void World::reportDeath(Organism* winner, Organism* loser) {
	// If loser was a Plant, that means it was eaten
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

void World::addOrganism(Organism* organism) {
	organisms.push_back(organism);
	reportSpawn(organism);
}

void World::saveWorld() {
	std::ofstream saveFile(SaveFilename);
	if (saveFile.is_open()) {
		for (Organism* organism : organisms) {
			saveFile << organism->serialize() << std::endl;
		}
		saveFile.close();
		std::cout << "World saved!" << std::endl;
	} else {
		std::cout << "Failed to create/write to: " << SaveFilename << "." << std::endl;
	}
}

void World::loadWorld() {
	std::ifstream saveFile(SaveFilename);
	std::string serializedOrganism;
	if (saveFile.is_open()) {
		organisms.clear();

		while (std::getline(saveFile, serializedOrganism)) {
			// Extract values
			std::stringstream fieldStream(serializedOrganism);
			std::string field;
			std::vector<std::string> fields;
			while (std::getline(fieldStream, field, ',')) {
				fields.push_back(field);
			}

			// Convert to appropriate types
			std::string type = fields[0];
			int age = std::stoi(fields[1]);
			int strength = std::stoi(fields[2]);
			int x = std::stoi(fields[3]);
			int y = std::stoi(fields[4]);
			int prevX = std::stoi(fields[5]);
			int prevY = std::stoi(fields[6]);
			
			// Create the organism and restore its properties
			Organism* organism = OrganismFactory::getInstance().create(type, x, y, this);
			organism->setAge(age);
			organism->setStrength(strength);
			organism->setPrevPosition(Position(prevX, prevY));

			// Restore Human-specific fields
			if (Human* human = dynamic_cast<Human*>(organism)) {
				bool magicalPotionActive = fields[7] == "1";
				int magicalPotionCooldown = std::stoi(fields[8]);
				human->setMagicalPotionActive(magicalPotionActive);
				human->setMagicalPotionCooldown(magicalPotionCooldown);
			}

			addOrganism(organism);
		}

		saveFile.close();
		std::cout << "World loaded from save!" << std::endl;
	} else {
		std::cout << "Failed to open/read from: " << SaveFilename << "." << std::endl;
	}
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
	std::vector<Position> neighbors = position.getNeighbors();
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