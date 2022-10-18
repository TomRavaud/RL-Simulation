#include <Imagine/Graphics.h>

#include "simulator.hpp"
#include "robot.hpp"
#include "laser.hpp"


int main()
{
    // Instantiate a simulation environment
    Simulator mySimulator;

    // Initialize the pose of the robot (and the laser)
    const pose2D initPose = {450, 120, 0};

    // Instantiate a robot and a laser
    Robot myRobot(20, initPose);
    Laser myLaser(initPose);

    // Start the simulator
    mySimulator.display();

    while(!myRobot.collision(mySimulator))
    {
        // Draw the grid and the robot
        mySimulator.drawMap();
        myRobot.draw();

        // Compute the length of the laser's rays and draw them
        myLaser.computeDistances(mySimulator);
        myLaser.drawRays();

        // Draw what was buffered
        Imagine::noRefreshEnd();

        // Set the simulation rate (about 50Hz)
        Imagine::milliSleep(20);

        // Start to buffer 2d drawings
        Imagine::noRefreshBegin();

        // Erase the robot and compute its next pose based on user's keypresses
        myRobot.erase();
        myRobot.teleop();
        myRobot.action();

        myLaser.eraseRays();

        // Move the laser's origin with the robot
        myLaser.update(myRobot);
    }

    Imagine::endGraphics();
    return 0;
}
