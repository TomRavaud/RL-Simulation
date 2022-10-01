#pragma once

#include <Imagine/Graphics.h>

class simulator
{
private:
    int width;
    int height;
public:
    /**
     * @brief Construct a new simulator object
     * 
     * @param w Width of the window
     * @param h Height of the window
     */
    simulator(int w, int h);

    /**
     * @brief Display the simulation window
     * 
     */
    void display() const;
};
