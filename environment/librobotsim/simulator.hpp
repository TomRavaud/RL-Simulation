#pragma once

#include <Imagine/Graphics.h>
#include "utils.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define CELL_SIZE 80

class Simulator
{
private:
    const int WIDTH = WINDOW_WIDTH;
    const int HEIGHT = WINDOW_HEIGHT;
    const int CELLSIZE = CELL_SIZE;

    // World grid
    const bool GRID[WINDOW_HEIGHT / CELL_SIZE][WINDOW_WIDTH / CELL_SIZE] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

public:
    /**
     * @brief Get the window width
     * 
     * @return int 
     */
    inline int getWindowWidth() const
    {
        return WIDTH;
    }

    /**
     * @brief Get the window height
     * 
     * @return int 
     */
    inline int getWindowHeight() const
    {
        return HEIGHT;
    }

    /**
     * @brief Get the cell size
     * 
     * @return int 
     */
    inline int getCellSize() const
    {
        return CELLSIZE;
    }

    /**
     * @brief Get the grid cell value
     * 
     * @param cell 
     * @return true 
     * @return false 
     */
    inline bool getGridCell(vector2D cell) const
    {
        return GRID[int(cell.y)][int(cell.x)];
    }

    /**
     * @brief Display the simulation window
     * 
     */
    void display() const;

    /**
     * @brief Draw the grid
     * 
     */
    void drawMap() const;
};
