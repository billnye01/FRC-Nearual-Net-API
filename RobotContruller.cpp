#include "RobotContruller.h"

RobotContruller::RobotContruller()
{
    robots = vector<Robot*>(6);
}

void RobotContruller::setRobot(Robot& robotIn, int i)
{
    robots[i] = &robotIn;
}

void RobotContruller::setRobot(Robot* robotIn, int i)
{
    robots[i] = robotIn;
}

void RobotContruller::ModifiRobot(std::vector<float> in, int i)
{
    robots[i]->change(in);
}

void RobotContruller::UpdateAll()
{
    for (int i = 0; i < robots.size(); i++) {
        robots[i]->update();
    }
}

std::vector<float> RobotContruller::getRobotValues(int i)
{

    return robots[i]->getValues();
}

std::vector<float> RobotContruller::getAllRobotValues()
{
    vector<float> out;

    for (int i = 0; i < robots.size(); i++) {
        vector<float> robotValues = getRobotValues(i);
        for (int j = 0; j < robotValues.size(); j++) {
            out.push_back(robotValues[j]);
        }
    }

    return out;
}

vector<int> RobotContruller::getScores()
{
    vector<int> out(robots.size());

    for (int i = 0; i < robots.size(); i++) {
        out[i] = robots[i]->getScore();
    }

    return out;
}

Robot& RobotContruller::getRobot(int i)
{
    return *robots[i];
}

void RobotContruller::Reset()
{
    for (int i = 0; i < robots.size(); i++) {
        robots[i]->resetRobot();
    }
}
