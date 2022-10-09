#include "simulator.h"

void Simulator::display() const
{
    Imagine::openWindow(WIDTH, HEIGHT, "Simulator");
}

void Simulator::drawMap() const
{
    // Color cells which correspond to obstacles
    for (int i = 0; i < HEIGHT/CELLSIZE; i++)
    {
        for (int j = 0; j < WIDTH/CELLSIZE; j++)
        {
            if (GRID[i][j] == 1)
            {
                Imagine::fillRect(j*CELLSIZE, i*CELLSIZE,
                                  CELLSIZE, CELLSIZE, Imagine::BLUE);
            }
        }
    }
    
    // Draw horizontal lines
    for (int i = 0; i < HEIGHT/CELLSIZE+1; i++)
    {
        Imagine::drawLine(0, i*CELLSIZE, WIDTH, i*CELLSIZE, Imagine::BLACK);
    }

    // Draw vertical lines
    for (int j = 0; j < WIDTH/CELLSIZE+1; j++)
    {
        Imagine::drawLine(j*CELLSIZE, 0, j*CELLSIZE, WIDTH, Imagine::BLACK);
    }
}
