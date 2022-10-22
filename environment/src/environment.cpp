#include <ros/ros.h>
#include <Imagine/Graphics.h>
#include <sensor_msgs/LaserScan.h>

#include "simulator.hpp"
#include "robot.hpp"
#include "laser.hpp"

// argc is the number of command line arguments and argv the list of arguments
int main(int argc, char **argv)
{
    // Initialize the node
    ros::init(argc, argv, "environment");
    // Allows us to create topics, services and actions (implicit with Python)
    ros::NodeHandle node;

    // Initialize a publisher to the laser topic, with a given buffer size
    ros::Publisher pub_laser = node.advertise<sensor_msgs::LaserScan>("laser", 1);

    // Set a publishing rate
    ros::Rate rate(20);

    // Instantiate a simulation environment
    Simulator mySimulator;

    // Initialize the pose of the robot (and the laser)
    const pose2D initPose = {450, 120, 0};

    // Instantiate a robot and a laser
    Robot myRobot(20, initPose);
    Laser myLaser(initPose);

    // Start the simulator
    mySimulator.display();

    // while the node has not received a ^C
    while (ros::ok())
    {
        // Draw the grid and the robot
        mySimulator.drawMap();
        myRobot.draw();

        // Compute the length of the laser's rays, publish them in the
        // corresponding ROS topic and draw them in the simulator
        myLaser.computeDistances(mySimulator);

        // Instantiate a LaserScan message
        sensor_msgs::LaserScan laserScan;

        // Fill the message
        laserScan.header.stamp = ros::Time::now();
        laserScan.header.frame_id = "laser_frame";
        laserScan.angle_min = -myLaser.getFov()/2;
        laserScan.angle_max = myLaser.getFov()/2;
        laserScan.angle_increment = myLaser.getFov()/myLaser.getNumberOfRays();
        //TODO: time_increment = 1/(laserFrequency*numberOfRays)
        laserScan.range_min = myLaser.getDistanceMin();
        laserScan.range_max = myLaser.getDistanceMax();

        double ranges[myLaser.getNumberOfRays()];
        myLaser.getRaysLengths(ranges, myLaser.getNumberOfRays());
        
        laserScan.ranges.resize(myLaser.getNumberOfRays());
        for (int i=0; i<myLaser.getNumberOfRays(); i++)
        {
            laserScan.ranges[i] = ranges[i];
        }

        // Publish the LaserScan message
        pub_laser.publish(laserScan);

        myLaser.drawRays();

        // Draw what was buffered
        Imagine::noRefreshEnd();

        rate.sleep();

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