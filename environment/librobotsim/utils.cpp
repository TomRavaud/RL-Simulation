#include "utils.hpp"

pose2D pose2D::operator+(vector2D displacement)
{
    pose2D newPose;
    newPose.position.x = position.x + displacement.x;
    newPose.position.y = position.y + displacement.y;
    return newPose;
}

vector2D vector2D::operator*(float k)
{
    vector2D newVector;
    newVector.x = k * x;
    newVector.y = k * y;
    return newVector;
}

int keypress()
{
	Imagine::Event e;
	do {
		getEvent(0, e);
		if(e.type == Imagine::EVT_KEY_ON)
			return e.key;
	} while (e.type != Imagine::EVT_NONE);
	return 0;
}
