#pragma once

#include "Entdy.h"

#include "vector"
#include <iostream>

using namespace std;

class Robot
{

public:
	Robot(Entdy* entdy, bool BlueSide);

	void update();

	void change(std::vector<float> inputs);
	std::vector<float> getValues();

	double getScore();

	void resetRobot();

private:
	Entdy* robot;
	int xStartingPos;
	int yStartingPos;

	float XChange = 0;
	float YChange = 0;
	float Omega = 0;

	bool BlueSide;

	float Score;
};

