#pragma once

#include "utils.h"
#include "robot.h"
#include "ray.h"
#include "simulator.h"

class Laser
{
private:
    // Pose of the laser
    pose2D pose;

    //TODO: Take the frequency into account
    const float FREQUENCY = 10.;

    const float FOV = M_PI_2;
    const int NUMBER_OF_RAYS = 5;

    //TODO: Take care of distances limits
    const double DISTANCE_MIN = 0.;
    const double DISTANCE_MAX = 1000.;

    //TODO: Take noise into account
    float noise;

    Ray* rays;

public:
    /**
     * @brief Construct a new Laser object
     * 
     * @param initPose 
     */
    Laser(pose2D initPose);

    /**
     * @brief Destroy the Laser object
     * 
     */
    ~Laser();

    /**
     * @brief Compute rays' length to obstacles
     * 
     * @param mySimulator 
     */
    void computeDistances(Simulator mySimulator);

    /**
     * @brief Update the pose of the laser given the pose of the robot
     * 
     * @param myRobot 
     */
    void update(Robot myRobot);

    /**
     * @brief Draw the laser's rays
     * 
     */
    void drawRays() const;

    /**
     * @brief Erase the laser's rays
     * 
     */
    void eraseRays() const;
};
