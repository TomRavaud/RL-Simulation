#pragma once

#include <Imagine/Graphics.h>
#include "utils.hpp"
#include "simulator.hpp"


class Robot
{
private:
    // Robot displacement step
    const int DISPLACEMENT = 2;
    
    // Robot angular step
    const double ROTATION_ANGLE = M_PI/12;

    // Radius of the circle representing the robot
    int size;

    // Identify robot's action : move (3), turn right (0) or turn left (1)
    int id_action;

    Imagine::Color color = Imagine::RED;
    
    // Position (2T) and orientation (1R) of the robot
    pose2D pose;

public:
    /**
     * @brief Construct a new robot object
     * 
     * @param s Size of the robot
     * @param initPose Initial pose of the robot
     */
    Robot(int s, pose2D initPose);

    /**
     * @brief Get the pose of the robot
     * 
     * @return pose2D 
     */
    inline pose2D getPose() const
    {
        return pose;
    }

    /**
     * @brief Draw the robot on the map
     * 
     */
    inline void draw() const
    {
        // Represent the robot with a filled circle
        Imagine::fillCircle(pose.position.x, pose.position.y, size, Imagine::RED);
        // Indicate the center of the robot
        Imagine::fillCircle(pose.position.x, pose.position.y, 2, Imagine::BLACK);
    }

    /**
     * @brief Remove the robot from the map
     * 
     */
    inline void erase() const
    {
        // Give the robot the background color to make it disappear
        Imagine::fillCircle(pose.position.x, pose.position.y, size, Imagine::WHITE);
    }

    /**
     * @brief Make the robot move forward
     * 
     */
    void move();

    /**
     * @brief Make the robot turn
     * 
     * @param direction right (0) or left (1)
     */
    void turn(int direction);

    /**
     * @brief Choose the action of the robot on keypresses
     * 
     */
    void action();

    /**
     * @brief Detect collisions with horizontal and vertical walls
     * 
     * @param mySimulator 
     * @return true (if a wall is hit)
     * @return false (else)
     */
    bool collision(Simulator mySimulator) const;

    /**
     * @brief Change the robot's direction according to user's keypresses
     * 
     */
    void teleop();
};
