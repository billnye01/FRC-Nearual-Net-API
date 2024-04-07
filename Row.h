#pragma once

#include "Cell.h"

class Row
{

public:
	Row(int amountOfInputs, int amountOfOutputs);
	Row(vector<Cell> cells);

	vector<Cell> getCells();
	vector<cellValues*> getCellValues();

	void setCells(vector<Cell> cells);

	void ModfiCells(float minWeights, float maxWeights, float minBais, float maxBais);
	void RandomizeCells(float minWeights, float maxWeights, float minBais, float maxBais);

	vector<float> out(vector<float> in);

private:
	vector<Cell> cells;
	int amountOfInputs;


};

