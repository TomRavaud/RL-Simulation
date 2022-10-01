#include <Imagine/Graphics.h>

#include "robot.h"

robot::robot(int w, int h, pose2D initPose)
{
    width = w;
    height = h;
    pose = initPose;
}

void robot::draw()
{
    Imagine::fillRect(pose.x - width/2, pose.y - height/2, width, height, color);
}