#include "Saving.h"

Saving::Saving(std::string filePath)
{
	FilePath = filePath;
}

Saving::Saving(std::string filePath, bool CreateFile)
{
}

Saving::Saving()
{
	FilePath = "NULL";
}

void Saving::SaveData(Brain in, std::string filePath)
{
	std::ofstream file;

	if (filePath == "NULL") {
		file.open(FilePath);
	}
	else
	{
		file.open(filePath);
	}

	if (!file.is_open()) {
		cout << "File Not Open When Saving\n";
		return;
	}

	cout << "Start Saving\n";

	file.clear();

	// runs for every row
	for (int RowIndex = 0; RowIndex < in.getRows().size(); RowIndex++) {

		Row row = in.getRows()[RowIndex];

		//runs for every row in cell
		for (int CellIndex = 0; CellIndex < row.getCells().size(); CellIndex++) {

			file << "Cell" << std::endl;
			file << CellIndex << endl;

			cellValues cell = row.getCells()[CellIndex].getCellValues();
			cout << "Weight Size: " << cell.Weights.size() << endl;

			for (int WeightIndex = 0; WeightIndex < cell.Weights.size(); WeightIndex++) {
				file << WeightIndex << std::endl;
				file << cell.Weights[WeightIndex] << endl;
				cout << endl;
			}

			file << "Bais" << std::endl;
			file << cell.Bais << std::endl;

		}

		file << "Row" << std::endl;
		file << RowIndex << endl;

	}

	file.close();
}

Brain Saving::getData(std::string filePath)
{

	vector<Row> rows;

	std::ifstream file;

	if (filePath == "NULL") {
		file.open(FilePath);
	}
	else
	{
		file.open(filePath);
	}

	if (!file.is_open()) {
		std::cout << "File not open when loading\n";
		//return nullptr;
	}

	std::cout << "Start Loading\n";

	bool Running = true;
	int lineOn = 0;
	int InputSize;

	cellValues CellValues;
	CellValues.Weights.clear();

	vector<Cell> cells;

	bool InCell = false;

	while (file.good())
	{
		std::string First;
		std::string Secound;
		file >> First;
		file >> Secound;

		if (First == "Row") {

			cout << "Loaded New Row\n";

			rows.push_back(Row(cells));
			cells.clear();
		}
		else if (First == "Cell")
		{
			cout << "Loaded New Cell\n";
			InCell = true;
		}
		else if (First == "Bais")
		{
			CellValues.Bais = stof(Secound);
			cells.push_back(Cell(CellValues));

			cout << "created Bais of: " << CellValues.Bais << "\n";
			cout << "Weight size of: " << CellValues.Weights.size() << "\n";

			cout << "End Loading a cell\n";


			CellValues = cellValues();
			CellValues.Weights = vector<float>(0);
			InCell = false;
		}
		else if (InCell) {
			cout << "loaded a new weight: " << stof(Secound) << endl;
			CellValues.Weights.push_back(stof(Secound));
		}
		else if(First == " ")
		{
			Running = false;
		}

		std::cout << endl;

		lineOn++;
	}

	file.close();

	Brain brain = Brain(rows);

	return brain;
}

bool Saving::BrainSame(Brain class_1, Brain class_2)
{
	vector<Row> class_1Rows = class_1.getRows();
	vector<Row> class_2Rows = class_2.getRows();

	if (class_1Rows.size() != class_2Rows.size()) {
		return false;
	}

	for (int i = 0; i < class_1Rows.size(); i++) {
		vector<Cell> class_1Cells = class_1Rows[i].getCells();
		vector<Cell> class_2Cells = class_2Rows[i].getCells();

		if (class_1Cells.size() != class_2Cells.size()) {
			return false;
		}


	}

	return true;
}
