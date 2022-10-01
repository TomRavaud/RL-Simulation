#include "simulator.h"

simulator::simulator(int w, int h)
{
    width = w;
    height = h;
}

void simulator::display() const
{
    Imagine::openWindow(width, height);
}
