#include "Robot.h"

Robot::Robot(Entdy* entdy, bool BlueSide) :robot(entdy), BlueSide(BlueSide)
{
	xStartingPos = robot->x;
	yStartingPos = robot->y;
}

void Robot::update()
{
	//cout << "Update, X change -" << XChange << endl;



	Score += abs(XChange) + abs(YChange);
	robot->x += XChange;
	robot->y += YChange;
}

void Robot::change(std::vector<float> inputs)
{

	int SideModfi = 1;

	if (!BlueSide) {
		SideModfi = -1;
	}

	XChange = inputs[0] * SideModfi;
	YChange = inputs[1] * SideModfi;
	Omega = inputs[2] * SideModfi;

	if (robot->x > 1100) {
		if (XChange > 0) {
			XChange = 0;
		}
	}
	else if(robot->x < 50)
	{
		if (XChange < 0) {
			XChange = 0;
		}
	}

	if (robot->y > 600) {
		if (YChange > 0) {
			YChange = 0;
		}
	}
	else if (robot->y < 0)
	{
		if (YChange < 0) {
			YChange = 0;
		}
	}

}

std::vector<float> Robot::getValues()
{
	std::vector<float> out(6);

	out[0] = robot->x;
	out[1] = robot->y;
	out[2] = robot->x;
	out[3] = XChange;
	out[4] = YChange;
	out[4] = Omega;

	return out;
}

double Robot::getScore()
{
	return Score;
}

void Robot::resetRobot()
{
	robot->x = xStartingPos;
	robot->y = yStartingPos;
	Score = 0;
}
