#include "Row.h"

Row::Row(int amountOfInputs, int amountOfOutputs): amountOfInputs(amountOfInputs)
{

	cout << "Inside Row, Amount of inputs: " << amountOfInputs << endl;
	cout << "Inside Row, Amount of outputs: " << amountOfOutputs << endl;

	vector<Cell> m_cells;
	for (int i = 0; i < amountOfOutputs; i++)
	{
		cout << "Start loading cell" << i << "\n";
		m_cells.push_back(Cell(amountOfInputs));
	}

	cells = m_cells;
}

Row::Row(vector<Cell> cells)
{
	this->cells = cells;
}

vector<Cell> Row::getCells()
{
	return cells;
}

vector<cellValues*> Row::getCellValues()
{
	vector<cellValues*> out(cells.size());

	for (int i = 0; i < cells.size(); i++) {
		out[i] = cells[i].getCellValues_ptr();
	}

	return out;
}

void Row::setCells(vector<Cell> cells)
{
	this->cells = cells;

}

void Row::ModfiCells(float minWeights, float maxWeights, float minBais, float maxBais)
{
	cout << "Start Modfi Cells\n";
	for (int i = 0; i < cells.size(); i++) {
		cout << "Start Modfi Cells in cell" << i << "\n";
		cells[i].setBaisRandomlyOnARefrancePoint(minBais, maxBais);
		cells[i].setBaisRandomlyOnARefrancePoint(minWeights, maxWeights);
	}
}

void Row::RandomizeCells(float minWeights, float maxWeights, float minBais, float maxBais)
{
	for (int i = 0; i < cells.size(); i++) {
		cells[i].RandomlySetWeightsBais(minBais, maxBais);
		cells[i].RandomlySetWeights(minWeights, maxWeights);
	}
}

vector<float> Row::out(vector<float> in)
{
	cout << "starting row\n\n";
	vector<float> out(cells.size());

	for (int i = 0; i < cells.size(); i++) {
		//cout << "starting cell with id : " << i << "\n";
		out[i] = cells[i].getValue(in);
	}

	return out;
}
