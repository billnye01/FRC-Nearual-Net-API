#pragma once

#include "RobotContruller.h"
#include "Brain.h"
#include "Saving.h"

#include <vector>
#include <algorithm>

using namespace std;

struct SimTemp
{
public:
	//vector<Robot*> rotots;
	RobotContruller* robotCon;
};

class Sim
{

public:
	Sim(SimTemp simTemp);

	void Start(bool Fresh, vector<int> rows = vector<int>(0));
	void StartLoad(string FileLoadPath);

	void Update();

	void End(string Save);

	void Reset();

private:

	bool sortF(int i, int j);

	vector<Brain> brain;
	RobotContruller* robotCon;
	Saving save;
	SimTemp simTemp;

	const float minChange = 1;
	const float maxChange = -1;

	const float minStart = -1;
	const float maxStart = 1;

};

