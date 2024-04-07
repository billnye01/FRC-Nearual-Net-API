#include "Brain.h"

Brain::Brain( vector<int> rowSizes, int outputSize, int inputSize)
{

    //rows = vector<Row>(0);
    this->inputSize = inputSize;
        for (int i = 0; i < rowSizes.size() + 1; i++) {

            if (i == 0) {
                cout << "Gen row 0 with input size of: " << inputSize << "\n";
                this->rows.push_back(Row(inputSize, rowSizes[0]));
            }
            else if (i == rowSizes.size())
            {
                cout << "Gen last row with input size of: " << rowSizes[i - 1] << "\n";
                this->rows.push_back(Row(rowSizes[i - 1], outputSize));
            }
            else
            {

                cout << "Gen row" << i << " row with input size of : " << rowSizes[i - 1] << "\n";
                this->rows.push_back(Row(rowSizes[i - 1], rowSizes[i]));
            }
            
        }

}

Brain::Brain(vector<Row> rows)
{

    cout << rows.size() << endl;
    this->rows = rows;
    inputSize = rows[0].getCellValues()[0]->Weights.size() - 1;

}

/*
Brain::Brain(vector<Row> rows, int inputSize)
{
    this->inputSize = inputSize;
    this->rows = rows;
}*/

void Brain::BrainRandomize(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais)
{

    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].RandomizeCells(minValueWeights, maxValueWeights, minValueBais, maxValueBais);
    }
}

void Brain::BrainRandomizeRow(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais, int index)
{
}

void Brain::setBrain(Brain brain)
{
    *this = brain;
}

void Brain::RandomiveBasedOnRefrance(float minValueWeights, float maxValueWeights, float minValueBais, float maxValueBais)
{
    cout << "Started randomizing based on ref\n";
    for (int i = 0; i < rows.size(); i++)
    {
        cout << "Started randomizing based on ref, row: " << i << "\n";
        rows[i].ModfiCells(minValueWeights, maxValueWeights, minValueBais, maxValueBais);
    }
}

vector<float> Brain::out(vector<float> input)
{

    cout << "Start Brain Cal\n";

    vector<float> PastOutputs = input;

    if (input.size() < inputSize) {
        cout << "Incorrect Input Size, Required input size: " << input.size() << ", input size: " << inputSize << endl;
        return vector<float>(0);
    }

    for (int i = 0; i < rows.size(); i++) {
        PastOutputs = rows[i].out(PastOutputs);
    }

    return PastOutputs;
}

Brain Brain::getBrain()
{
    return *this;
}

Brain* Brain::getBrain_prt()
{
    return this;
}

vector<Row> Brain::getRows()
{
    return rows;
}

vector<Row>* Brain::getRows_prt()
{
    return &rows;
}

Row* Brain::getRowsIndex_prt(int index)
{
    return &rows[index];
}

Row Brain::getRowsIndex(int index)
{
    return rows[index];
}
