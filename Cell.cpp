#include "Cell.h"

#include <vector>

Cell::Cell(int amountOfInputs) {
	cellvalues.Weights = vector<float>(amountOfInputs);
}

Cell::Cell(cellValues cellvalues)
{
	this->cellvalues = cellvalues;
}

void Cell::RandomlySetWeights(float Min, float Max)
{
	vector<float> weights(cellvalues.Weights.size());

	for (int i = 0; i < weights.size(); i++)
	{
		weights[i] = getRandomNumberInRange(Min, Max);
		cout << "Weight index " << i << " value: " << weights[i] << " And Random number: " << rand() << "\n";
	}

	cellvalues.Weights = weights;
}

void Cell::RandomlySetWeightsBais(float Min, float Max)
{
	cellvalues.Bais = getRandomNumberInRange(Min, Max);
	cout << "Bais value: " << cellvalues.Bais << " And Random number: " << rand() << "\n";
}

void Cell::setCellValues(cellValues m_cellValues)
{
	cellvalues = m_cellValues;
}

void Cell::setBais(float m_Bais)
{
	cellvalues.Bais = m_Bais;
}

void Cell::setWeights(vector<float> m_Weights)
{
	cellvalues.Weights = m_Weights;
}

void Cell::setWeightsRandomlyOnARefrancePoint(float MaxUp, float MinDown)
{
	cout << "start modfi weights\n";

	for (int i = 0; i < cellvalues.Weights.size(); i++) {

		cellvalues.Weights[i] += getRandomNumberInRange(MinDown, MaxUp);

		if (cellvalues.Weights[i] > 1) {
			cellvalues.Weights[i] = 1;
		}
		else if (cellvalues.Weights[i] < -1) {
			cellvalues.Weights[i] = -1;

		}
	}
}

void Cell::setBaisRandomlyOnARefrancePoint(float MaxUp, float MinDown)
{
	cout << "start modfi bais\n";

	cellvalues.Bais += getRandomNumberInRange(MinDown, MaxUp);

}

float Cell::getValue(vector<float> Inputs)
{
	if (Inputs.size() < cellvalues.Weights.size()) {
		cout << "Inputs inputs to small compaired to weights, weights size: " << cellvalues.Weights.size() << " Inputs size: " << Inputs.size() << "\n";
		return 0;
	}

	float out = 0;

	for (int i = 0; i <  cellvalues.Weights.size(); i++)
	{

		out += Inputs[i] * cellvalues.Weights[i];
	}

	out += cellvalues.Bais;

	//sigmoid
	out = out / (1 + abs(out));

	return out;
}

cellValues Cell::getCellValues()
{
	return cellvalues;
}

cellValues* Cell::getCellValues_ptr()
{
	return &cellvalues;
}

float Cell::getRandomNumberInRange(float min, float max)
{

	// Create a random device to seed the random number engine
	std::random_device rd;
	// Create a Mersenne Twister pseudo-random number generator
	std::mt19937 gen(rd());
	// Define the distribution for the random number (here, between 0 and 1)
	std::uniform_real_distribution<double> dis(min, max);

	// Generate a fully random number
	double randomNumber = dis(gen);

	return randomNumber;

	//cout << "randomNumber: " << abs(rand()) * (max - min) + max << endl;
	//return abs(randomNumber) * (max - min) + max;

	/*
	uniform_int_distribution<int> dist(min, max);
	return dist(rd);*/
}
