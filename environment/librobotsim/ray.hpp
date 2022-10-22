#pragma once

#include "utils.hpp"

class Ray
{
private:
    Imagine::Color color = Imagine::GREEN;

    vector2D direction;
    double length;

    vector2D origin;

public:
    /**
     * @brief Get the ray's origin
     * 
     * @return vector2D 
     */
    inline vector2D getOrigin() const
    {
        return origin;
    }

    /**
     * @brief Set the ray's origin
     * 
     * @param ori 
     */
    inline void setOrigin(vector2D ori)
    {
        origin = ori;
    }

    /**
     * @brief Get the ray's direction
     * 
     * @return vector2D 
     */
    inline vector2D getDirection() const
    {
        return direction;
    }

    /**
     * @brief Set the ray's direction
     * 
     * @param dir 
     */
    inline void setDirection(vector2D dir)
    {
        direction = dir;
    }

    /**
     * @brief Get the length of the ray
     * 
     * @return double 
     */
    inline double getLength() const
    {
        return length;
    }

    /**
     * @brief Set the ray's length
     * 
     * @param l 
     */
    inline void setLength(double l)
    {
        length = l;
    }

    /**
     * @brief Draw the ray
     * 
     */
    inline void draw() const
    {
        Imagine::drawLine(origin.x, origin.y, origin.x + length*direction.x,
                          origin.y + length*direction.y, color, 2);
    }

    /**
     * @brief Erase the ray
     * 
     */
    inline void erase() const
    {
        Imagine::drawLine(origin.x, origin.y, origin.x + length*direction.x,
                          origin.y + length*direction.y, Imagine::WHITE, 2);
    }
};
