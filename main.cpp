#include <Imagine/Graphics.h>

#include "simulator.h"
#include "robot.h"

int main()
{
    simulator mySimulator(1000, 600);

    pose2D initPose;
    initPose.x = 100;
    initPose.y = 200;
    initPose.theta = 0;

    robot myRobot(30, 40, initPose);

    mySimulator.display();
    myRobot.draw();

    Imagine::endGraphics();
    return 0;
}
