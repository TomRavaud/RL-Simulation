#include "robot.h"

Robot::Robot(int s, pose2D initPose)
{
    size = s;
    pose = initPose;
}

void Robot::move()
{
    // Move the robot in the current direction
    pose.position.x += DISPLACEMENT*cos(pose.orientation);
    pose.position.y += DISPLACEMENT*sin(pose.orientation);
}

void Robot::turn(int direction)
{
    // Turn right
    if (direction == 0)
        pose.orientation += ROTATION_ANGLE;

    // Turn left
    else if (direction == 1)
    {
        pose.orientation -= ROTATION_ANGLE;
    }
}

void Robot::action()
{
    // Turn right
    if (id_action == 0)
        turn(0);

    // Turn left
    else if (id_action == 2)
        turn(1);
    
    // Move forward
    else if (id_action == 3)
        move();
}

bool Robot::collision(Simulator mySimulator) const
{
    const int CELLSIZE = mySimulator.getCellSize();

    // Check if the robots hits some vertical or horizontal wall
    if (mySimulator.getGridCell({double(int(pose.position.x + size)/CELLSIZE), double(int(pose.position.y)/CELLSIZE)}) ||
        mySimulator.getGridCell({double(int(pose.position.x - size)/CELLSIZE), double(int(pose.position.y)/CELLSIZE)}) ||
        mySimulator.getGridCell({double(int(pose.position.x)/CELLSIZE), double(int(pose.position.y + size)/CELLSIZE)}) ||
        mySimulator.getGridCell({double(int(pose.position.x)/CELLSIZE), double(int(pose.position.y - size)/CELLSIZE)}))
        {
            std::cout << "Collision !" << std::endl;
            return true;
        }

    return false;
}

void Robot::teleop()
{
    id_action = 4;

    int key = keypress();

    switch(key)
    {
        case int(Imagine::KEY_RIGHT):
            id_action = 0;
            break;
        case int(Imagine::KEY_DOWN):
            id_action = 1;
            break;
        case int(Imagine::KEY_LEFT):
            id_action = 2;
            break;
        case int(Imagine::KEY_UP):
            id_action = 3;
            break;
    }
}
