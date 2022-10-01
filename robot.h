#pragma once

#include <Imagine/Graphics.h>
#include "utils.h"

const vector2D DISPLACEMENT[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class robot
{
private:
    int width;
    int height;
    int direction;
    pose2D pose;
    Imagine::Color color = Imagine::RED;

public:
    /**
     * @brief Construct a new robot object
     * 
     * @param w Width of the robot
     * @param h Height of the robot
     * @param initPose Initial pose of the robot
     */
    robot(int w, int h, pose2D initPose);

    /**
     * @brief Draw the robot on the map
     * 
     */
    void draw() const;

    /**
     * @brief Remove the robot from the map
     * 
     */
    void erase() const;

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
