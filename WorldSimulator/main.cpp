#include <conio.h>
#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskysHogweed.h"

int main() {
	World* world = new World();
	world->randomSeed();

	/*
	world->populate({
		// Animals
		Human::spawn(4, 0, world),
		new Wolf(9, 3, world),
		new Wolf(6, 1, world),
		new Sheep(8, 1, world),
		new Sheep(9, 5, world),
		new Fox(6, 3, world),
		new Fox(8, 9, world),
		new Turtle(1, 1, world),
		new Turtle(1, 3, world),
		new Antelope(0, 8, world),
		new Antelope(6, 8, world),

		//// Plants
		new Grass(4, 2, world),
		new SowThistle(4, 8, world),
		new Guarana(2, 6, world),
		new Belladonna(7, 6, world),
		new SosnowskysHogweed(5, 5, world)
	});
	*/

	world->drawWorld();
	while (true) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
				case 'n':
					world->makeTurn();
					world->drawWorld();
					break;
				case 's':
					world->saveWorld();
					break;
				case 'l':
					world->loadWorld();
					world->drawWorld();
			}
		}
	}

	delete world;
}