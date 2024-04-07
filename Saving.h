#pragma once

#include<fstream>
#include<string>

#include "Brain.h"
class Saving
{

public:

	Saving(std::string filePath);
	Saving(std::string filePath, bool CreateFile);
	Saving();

	void SaveData(Brain in, std::string filePath = "NULL");

	Brain getData(std::string filePath = "NULL");

	bool BrainSame(Brain class_1, Brain class_2);

private:
	std::string FilePath;
};

