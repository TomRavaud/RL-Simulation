#include "robot.h"

robot::robot(int w, int h, pose2D initPose)
{
    width = w;
    height = h;
    pose = initPose;
    direction = 0;
}

void robot::draw() const
{
    // Represent the robot with a rectangle
    Imagine::fillRect(pose.x - width/2, pose.y - height/2, width, height, color);
    // Indicate the center of the robot
    Imagine::fillCircle(pose.x, pose.y, 2, Imagine::BLACK);
}

void robot::erase() const
{
    // Give the robot the background color to make it disappear
    Imagine::fillRect(pose.x - width/2, pose.y - height/2, width, height, Imagine::WHITE);
}

void robot::move()
{
    vector2D displacement = DISPLACEMENT[direction];
    displacement = displacement*2;

    pose = pose + displacement;
    vector2D test;
}

void robot::teleop()
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
        // default:
        //     std::cout << "You must use arrow keys to move the robot !" << std::endl;
        //     break;
    }
}
