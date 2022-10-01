#pragma once
#include "utils.h"

class robot
{
private:
    int width;
    int height;
    pose2D pose;
    Imagine::Color color = Imagine::RED;

public:
    robot(int w, int h, pose2D initPose);
    void draw();
};
