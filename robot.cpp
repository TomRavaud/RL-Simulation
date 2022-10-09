#include "robot.h"

Robot::Robot(int w, int h, pose2D initPose)
{
    width = w;
    height = h;
    pose = initPose;
    direction = 0;
}

void Robot::move()
{
    vector2D displacement = DISPLACEMENT[direction];
    // Two pixels displacement
    displacement = displacement*2;

    // Update the pose of the robot
    pose = pose + displacement;
}

void Robot::teleop()
{
    int key = keypress();

    switch(key)
    {
        case int(Imagine::KEY_RIGHT):
            direction = 0;
            break;
        case int(Imagine::KEY_DOWN):
            direction = 1;
            break;
        case int(Imagine::KEY_LEFT):
            direction = 2;
            break;
        case int(Imagine::KEY_UP):
            direction = 3;
            break;
    }
}
