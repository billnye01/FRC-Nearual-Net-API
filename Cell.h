#pragma once

#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

struct cellValues
{
	vector<float> Weights = vector<float>(1);
	float Bais = 0;
};

class Cell{


public:
	Cell(int amountOfInputs);
	Cell(cellValues cellvalues);

	void RandomlySetWeights(float Min, float Max);
	void RandomlySetWeightsBais(float Min, float Max);

	void setCellValues(cellValues m_cellValues);
	void setBais(float m_Bais);
	void setWeights(vector<float> m_Weights);

	void setWeightsRandomlyOnARefrancePoint(float MaxUp, float MinDown);
	void setBaisRandomlyOnARefrancePoint(float MaxUp, float MinDown);

	float getValue(vector<float> Inputs);

	cellValues getCellValues();
	cellValues* getCellValues_ptr();



private:

	float getRandomNumberInRange(float min, float max);


	cellValues cellvalues;

};

