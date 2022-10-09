#include <Imagine/Graphics.h>

#include "simulator.h"
#include "robot.h"
#include "laser.h"


int main()
{
    // Instantiate a simulation environment
    Simulator mySimulator;

    // Initialize the pose of the robot (and the laser)
    const pose2D initPose = {450, 120};

    // Instantiate a robot and a laser
    Robot myRobot(30, 40, initPose);
    Laser myLaser(initPose);

    // Start the simulator
    mySimulator.display();

    // Main simulation loop
    while(true)
    {
        // Draw the grid and the robot
        mySimulator.drawMap();
        myRobot.draw();

        // Compute the length of the laser's rays and draw them
        myLaser.computeDistances(mySimulator);
        myLaser.drawRays();

        // Set the simulation rate (about 50Hz)
        Imagine::milliSleep(20);

        // Erase the robot and compute its next pose based on user's keypresses
        myRobot.erase();
        myRobot.teleop();
        myRobot.move();

        myLaser.eraseRays();

        // Move the laser's origin with the robot
        myLaser.update(myRobot);
    }

    Imagine::endGraphics();
    return 0;
}
