#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant {
private:
	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	void killNeighboringAnimals();

public:
	SosnowskysHogweed(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};