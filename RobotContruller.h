#pragma once

#include "Robot.h"

class RobotContruller
{

public:
	RobotContruller();

	void setRobot(Robot& robotIn, int i);
	void setRobot(Robot* robotIn, int i);
	void ModifiRobot(std::vector<float> in, int i);

	void UpdateAll();

	std::vector<float> getRobotValues(int i);
	std::vector<float> getAllRobotValues();

	vector<int> getScores();

	Robot& getRobot(int i);

	void Reset();

private:
	std::vector<Robot*> robots;

};

