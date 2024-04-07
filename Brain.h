#pragma once
#include "Row.h"

class Brain
{

public:
	Brain( vector<int> rowSizes, int outputSize, int inputSize);
	Brain( vector<Row> rows);

	void BrainRandomize(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais);
	void BrainRandomizeRow(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais, int index);
	void RandomiveBasedOnRefrance(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais);


	vector<float> out(vector<float> input);

	void setBrain(Brain brain);

	Brain getBrain();
	Brain* getBrain_prt();
	vector<Row> getRows();
	vector<Row>* getRows_prt();

	Row* getRowsIndex_prt(int index);
	Row getRowsIndex(int index);

	int getInputSize();




private:
	vector<Row> rows;

	int inputSize = 0;

};

