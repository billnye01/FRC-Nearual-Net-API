
#include <iostream>
#include <vector>

#include "Entdy.h"
#include "RobotContruller.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "Saving.h"
#include "Brain.h"
#include "Sim.h"

bool sortF(int i, int j) { return (i < j); }

int main(int argc, char* argv[]){
	
	Saving save(std::string("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt"));

						//blue 0  //blue 1  //blue 2
	int RobotPosX[3] = {170,		  275,		500};
					    // top  // bottom
	int RobotPosY[2] = { 1100,    100 };

	int BlueScore = 0;
	int RedScore = 0;

	double ThreashouldToHit = 10;
	int PenltyFromHitting = 100;

	// makes the robots
	//RobotContruller robotContuller;

	SimTemp simTemp;
	RobotContruller robotContuller;

	//blue
	Robot RobotBlue1(Entdy(RobotPosY[1], RobotPosX[0], 0.1), true);
	Robot RobotBlue2(Entdy(RobotPosY[1], RobotPosX[1], 0.1), true);
	Robot RobotBlue3(Entdy(RobotPosY[1], RobotPosX[2], 0.1), true);

	//red
	Robot RobotRed1(Entdy(RobotPosY[0], RobotPosX[0], 0.1), false);
	Robot RobotRed2(Entdy(RobotPosY[0], RobotPosX[1], 0.1), false);
	Robot RobotRed3(Entdy(RobotPosY[0], RobotPosX[2], 0.1), false);

	robotContuller.setRobot(RobotBlue1, 0);
	robotContuller.setRobot(RobotBlue2, 1);
	robotContuller.setRobot(RobotBlue3, 2);
	robotContuller.setRobot(RobotRed1, 3);
	robotContuller.setRobot(RobotRed2, 4);
	robotContuller.setRobot(RobotRed3, 5);

	simTemp.robotCon = &robotContuller;

	Sim sim(simTemp);
	sim.Start(true, {10, 10});

	/*
	// sets the robots in robotContuller
	robotContuller.setRobot(blue1, 0);
	robotContuller.setRobot(blue2, 1);
	robotContuller.setRobot(blue3, 2);
	robotContuller.setRobot(red1, 3);
	robotContuller.setRobot(red2, 4);
	robotContuller.setRobot(red3, 5);

	Brain blue1_B( { 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue1_B.BrainRandomize(-1, 1, -1, 1);

	save.SaveData(blue1_B);

	Brain brainSave = save.getData();
	 
	Brain blue2_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue2_B.BrainRandomize(-1, 1, -1, 1);

	Brain blue3_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue3_B.BrainRandomize(-1, 1, -1, 1);

	Brain red1_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red1_B.BrainRandomize(-1, 1, -1, 1);

	Brain red2_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red2_B.BrainRandomize(-1, 1, -1, 1);

	Brain red3_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red3_B.BrainRandomize(-1, 1, -1, 1);*/


	bool GameRuning = true;

	while (GameRuning) {

		for (int i = 0; i < 3; i++) {

			if (i != 0) {
				sim.StartLoad("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
			}

			int cycalls = 600;
			bool runing = true;
			while (cycalls > 0)
			{
				cout << cycalls << "\n\n\n";

				sim.Update();
				cycalls--;
			}
			
			sim.End("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
			sim.Reset();
		}

	}

	sim.End("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
	
	return 0;
}