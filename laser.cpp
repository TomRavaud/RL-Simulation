#include "laser.h"

Laser::Laser(pose2D initPose)
{
    // Initialize the pose of the laser
    pose = initPose;

    // Allocate storage for laser's rays
    rays = new Ray[NUMBER_OF_RAYS];

    // Compute the angle step between two consecutive rays
    const float ANGLE_STEP = FOV / (NUMBER_OF_RAYS-1);

    // Set initial origin and direction of the rays
    for(int k = 0; k < NUMBER_OF_RAYS; k++)
    {
        rays[k].setOrigin(pose.position);

        float rayAngle = -FOV/2 + k*ANGLE_STEP;
        rays[k].setDirection({cos(M_PI/2 + rayAngle), sin(M_PI/2 + rayAngle)});
    }
}

Laser::~Laser()
{
    delete[] rays;
}

void Laser::computeDistances(Simulator mySimulator)
{
    const int CELLSIZE = mySimulator.getCellSize();
    const int WIDTH = mySimulator.getWindowWidth();
    const int HEIGHT = mySimulator.getWindowHeight();

    for (int k = 0; k < NUMBER_OF_RAYS; k++)
    {
        // Compute grid coordinates of the cell the laser is in
        vector2D gridCell = {double(int(pose.position.x) / CELLSIZE),
                             double(int(pose.position.y) / CELLSIZE)};

        const vector2D rayDir = rays[k].getDirection();
        const vector2D rayOrigin = rays[k].getOrigin();

        // Length of the ray between two consecutive vertical/horizontal lines of the grid
        const vector2D rayStep = {CELLSIZE * sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x)),
                                  CELLSIZE * sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y))};

        // Length of the ray from the origin to the last vertical/horizontal line of the grid
        vector2D rayLength = {0., 0.};

        // Determine how we should move on the grid at the next iteration
        vector2D step = {0., 0.};

        // Compute the distance from the origin of the ray
        // and the first vertical/horizontal line of the grid
        if (rayDir.x < 0)
        {
            step.x = -1;
            rayLength.x = sqrt(pow(gridCell.x * CELLSIZE - rayOrigin.x, 2) +
                               pow(rayDir.y/rayDir.x * (gridCell.x * CELLSIZE - rayOrigin.x), 2));
        }
        else
        {
            step.x = 1;
            rayLength.x = sqrt(pow((gridCell.x + 1) * CELLSIZE - rayOrigin.x, 2) +
                               pow(rayDir.y/rayDir.x * ((gridCell.x + 1) * CELLSIZE - rayOrigin.x), 2));
        }

        if (rayDir.y < 0)
        {
            step.y = -1;
            rayLength.y = sqrt(pow(rayDir.x/rayDir.y * (gridCell.y * CELLSIZE - rayOrigin.y), 2) +
                               pow(gridCell.y * CELLSIZE - rayOrigin.y, 2));
        }
        else
        {
            step.y = 1;
            rayLength.y = sqrt(pow(rayDir.x/rayDir.y * ((gridCell.y + 1) * CELLSIZE - rayOrigin.y), 2) +
                               pow((gridCell.y + 1) * CELLSIZE - rayOrigin.y, 2));
        }

        // This condition becomes true is the ray hits an obstacle
        bool isHit = false;

        // Initialize the true length of the ray
        double length = 0.;

        // Digital Differential Analyser (DDA) algorithm loop
        // The ray length is increased cell after cell
        // until it hits a wall or leaves the window
        while (!isHit && length < DISTANCE_MAX &&
               gridCell.x >= 0 && gridCell.x < 8 &&
               gridCell.y >= 0 && gridCell.y < 6)
        {
            if (rayLength.x < rayLength.y)
            {
                gridCell.x += step.x;
                length = rayLength.x;
                rayLength.x += rayStep.x;
            }
            else
            {
                gridCell.y += step.y;
                length = rayLength.y;
                rayLength.y += rayStep.y;
            }

            if (mySimulator.getGridCell(gridCell))
            {
                isHit = true;
            }
        }
        rays[k].setLength(length);
    }
}

void Laser::update(Robot myRobot)
{
    // Update the pose of the laser
    pose.position = myRobot.getPose().position;

    const float ANGLE_STEP = FOV / (NUMBER_OF_RAYS-1);

    // Update the origin and the direction of each ray
    for (int k = 0; k < NUMBER_OF_RAYS; k++)
    {
        rays[k].setOrigin(pose.position);

        float robotOrientation = myRobot.getPose().orientation;
        float rayAngle = -FOV/2 + k*ANGLE_STEP;
        rays[k].setDirection({cos(robotOrientation + rayAngle), sin(robotOrientation + rayAngle)});
    }
}

void Laser::drawRays() const
{
    for (int k = 0; k < NUMBER_OF_RAYS; k++)
        rays[k].draw();
}

void Laser::eraseRays() const
{
    for (int k = 0; k < NUMBER_OF_RAYS; k++)
        rays[k].erase();
}
