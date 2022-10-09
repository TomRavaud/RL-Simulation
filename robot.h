#pragma once

#include <Imagine/Graphics.h>
#include "utils.h"

const vector2D DISPLACEMENT[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Robot
{
private:
    int width;
    int height;
    int direction;
    Imagine::Color color = Imagine::RED;

    pose2D pose;

public:

    /**
     * @brief Construct a new robot object
     * 
     * @param w Width of the robot
     * @param h Height of the robot
     * @param initPose Initial pose of the robot
     */
    Robot(int w, int h, pose2D initPose);

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
        // Represent the robot with a rectangle
        Imagine::fillRect(pose.position.x - width/2, pose.position.y - height/2, width, height, color);
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
        Imagine::fillRect(pose.position.x - width/2, pose.position.y - height/2, width, height, Imagine::WHITE);
    }

    /**
     * @brief Make the robot moving
     * 
     */
    void move();

    /**
     * @brief Change the robot's direction according to user's keypresses
     * 
     */
    void teleop();
};
