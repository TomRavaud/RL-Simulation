#pragma once

#include <Imagine/Graphics.h>

struct vector2D
{
    double x;
    double y;

    /**
     * @brief Multiply a vector by a scalar
     * 
     * @param k 
     * @return vector2D 
     */
    vector2D operator*(float k);
};

struct pose2D
{
    vector2D position;
    // int theta;

    /**
     * @brief Change the pose given a displacement vector
     * 
     * @param displacement Displacement vector
     * @return pose2D 
     */
    pose2D operator+(vector2D displacement);
};

/**
 * @brief Get user's keypresses
 * 
 * @return int Key number
 */
int keypress();
