#include "Sim.h"

Sim::Sim(SimTemp simTemp)
{

	cout << "Sim Init\n";
	this->simTemp = simTemp;
	robotCon = simTemp.robotCon;
	/*
	for (int i = 0; i < simTemp.rotots.size(); i++) {
		//robotCon.setRobot(simTemp.rotots[i], i);
		//brain = vector<Brain>(simTemp.rotots.size());
	}*/
}

void Sim::Start(bool Fresh, vector<int> rows)
{
	cout << "Sim start\n";
	if (Fresh) {
		for (int i = 0; i < robotCon->getAllRobotValues().size() / 6; i++) {
			brain.push_back(Brain(rows, 3, robotCon->getAllRobotValues().size()));
			brain[i].BrainRandomize(minStart, maxStart, minStart, maxStart);
		}
		return;
	}

	for (int i = 0; i < robotCon->getAllRobotValues().size() / 6; i++) {
		brain[i].RandomiveBasedOnRefrance(minChange, maxChange, minChange, maxChange);
	}
}

void Sim::StartLoad(string FileLoadPath)
{
	brain.clear();
	Brain brainTmp = save.getData(FileLoadPath);

	cout << "SIM, Started Loading\n";
	for (int i = 0; i < robotCon->getAllRobotValues().size() / 6; i++) {
		brain.push_back(brainTmp);
		brain[i].RandomiveBasedOnRefrance(minChange, maxChange, minChange, maxChange);
	}
}

void Sim::Update()
{

	for (int i = 0; i < brain.size(); i++) {
		robotCon->ModifiRobot(brain[i].out(robotCon->getAllRobotValues()), i);
	}
	robotCon->UpdateAll();
}

void Sim::End(string Save)
{

	cout << "End Sim\n";

	vector<int> bestRobots = robotCon->getScores();

	std::sort(bestRobots.begin(), bestRobots.end(), [](int a, int b) {
		return a > b; // Sort in descending order
		});

	for (int i = 0; i < robotCon->getScores().size(); i++) {
		if (bestRobots[0] == robotCon->getScores()[i]) {
			save.SaveData(brain[i], Save);
		}
	}

	
}

void Sim::Reset()
{
	cout << "Reset Sim\n";
	robotCon->Reset();
}

bool Sim::sortF(int i, int j)
{
	return i < j;
}

