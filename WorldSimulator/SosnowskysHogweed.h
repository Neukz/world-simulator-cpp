#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant {
private:
	static const int Strength = 10;
	static const char Symbol = 'h';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	void killNeighboringAnimals();

public:
	SosnowskysHogweed(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};