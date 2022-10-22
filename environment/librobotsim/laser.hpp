#pragma once

#include "utils.hpp"
#include "robot.hpp"
#include "ray.hpp"
#include "simulator.hpp"

class Laser
{
private:
    // Pose of the laser
    pose2D pose;

    //TODO: Take the frequency into account
    const float FREQUENCY = 10.;

    // Laser's angular field of view
    const float FOV = M_PI_2;

    const int NUMBER_OF_RAYS = 10;

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
     * @brief Get the field of view of the laser
     * 
     * @return float 
     */
    inline float getFov() const
    {
        return FOV;
    }

    /**
     * @brief Get the minimal distance the laser can measure
     * 
     * @return double 
     */
    inline double getDistanceMin() const
    {
        return DISTANCE_MIN;
    }

    /**
     * @brief Get the maximal distance the laser can measure
     * 
     * @return double 
     */
    inline double getDistanceMax() const
    {
        return DISTANCE_MAX;
    }

    /**
     * @brief Get the number of rays of the laser
     * 
     * @return int 
     */
    inline int getNumberOfRays() const
    {
        return NUMBER_OF_RAYS;
    }

    /**
     * @brief Get the length of the rays
     * 
     * @param ranges rays' length
     * @param n number of rays
     */
    inline void getRaysLengths(double ranges[], int n) const
    {
        for (int i=0; i<n; i++)
        {
            ranges[i] = rays[i].getLength();
        }
    }

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
